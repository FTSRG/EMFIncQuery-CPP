/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *******************************************************************************/
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.QueryDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import javax.sound.sampled.BooleanControl.Type

/**
 * @author Robert Doczi
 */
class QueryGroupGenerator extends ViatraQueryHeaderGenerator {
		
	val QueryDescriptor query
	
	val boolean threadSafe
	
	new(QueryDescriptor query) {
		this(query, false)
	}
	
	new(QueryDescriptor query, boolean isThreadSafe){
		super(#{query.name}, '''«query.name.toFirstUpper»QueryGroup''')
		this.query = query
		this.threadSafe = isThreadSafe
	}
	
	override initialize() {
		if(threadSafe){
			includes += new Include("mutex", true)
			includes += new Include("thread", true)
			includes += new Include("atomic", true)
		}
		includes += new Include("Viatra/Query/Matcher/ISearchContext.h")
		includes += new Include("Viatra/Query/Matcher/ClassHelper.h")		
		includes += new Include("Viatra/Query/Matcher/ModelIndex.h")
		includes += query.classes.map[
			Include::fromEClass(it)	
		]
	}
	
	override compileInner() '''
		class «unitName»{
		public:
			static «unitName»* instance() {
				static «unitName» instance;
				return &instance;
			}
		
			const ::Viatra::Query::Matcher::ISearchContext* context() const {
				return &_isc;
			}
		
		private:
			«unitName»()
				: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
							«FOR clazz : query.classes»
								«val supers = clazz.EAllGenericSuperTypes.map[EClassifier]»
								«val typeHelper = CppHelper::getTypeHelper(clazz)»
								.forClass(«typeHelper.FQN»::type_id)«IF !supers.empty»«FOR s : supers.map[CppHelper::getTypeHelper(it)]».setSuper(«s.FQN»::type_id)«ENDFOR»«ELSE».noSuper()«ENDIF»
							«ENDFOR»
							.build() } {
			}
		
			::Viatra::Query::Matcher::ISearchContext _isc;
		};
	'''
	
	override compileOuter() '''
		namespace Viatra {
			namespace Query {
				
			class Any{
			private:
				class ContainerBase{
				public:
					virtual ~ContainerBase(){}
				};
				
				template<typename T>
				class Container : public ContainerBase{
				public:
					T data;
					Container(T const &modelRoot) : data(modelRoot) {}
				};
				
				ContainerBase* pdata;
			public:
				Any() :pdata(nullptr){}
				Any(Any const &to_copy) = delete;
				Any& operator(Any const& to_copy) = delete;
				~Any() { delete pdata; }
				
				//must implement T copy cstr properly
				template <typename T>
				void set(T const &modelRoot){
					ContainerBase *newpdata = new Container<T>(modelRoot);
					delete pdata;
					pdata = newpdata;
				}
				
				template <typename T>
				T& get(){
					return dynamic_cast<Container<T>&>(*pdata).data;
				}
				
				template <typename T>
				T const & get() const {
					return dynamic_cast<Container<T>&>(*pdata).data;
				}
			};
		
		    struct ModelRoot
		  	{
		  		«IF threadSafe»
		  		ModelRoot(): _number(1), _next(1) {
		  			for(int i = 0; i < n; i++) _turn[i] = 0;
		  		}
		  		«ELSE»
		  		ModelRoot(){}
		  		«ENDIF»
		
		  		~ModelRoot(){}
		  		
		  		Any root;
		  		
		  		«IF threadSafe»
		  		static atomic_int numThreads = 0; 
		  		const int n = 10;
		  		const std::chrono::milliseconds interval(10);
		  		atomic_int _number;
		  		atomic_int _next;
		  		atomic_int _turn[n];
		  		mutex resourceMutex;
		  		
		  		/*
		  		 * TICKET PROTOCOL
		  		 * If you want something to do as a critical 
		  		 * operation you need to follow these steps
		  		 * 1. id = getID()
		  		 * 2. getTicket(id)
		  		 * 3. wait()
		  		 * 4. resourceMutex.lock()
		  		 * 5. criticalBegin()
		  		 * 6. //Do critical job
		  		 * 7. criticalEnd()
		  		 * 8. resourceMutex.unlock()
		  		 * If any thread calls getTicket() need to wait() and need to call criticalEnd().
		  		 * If somewhere throws an interrupt, the mutex goes in deadlock.
		  		 * TODO: implement guarder or other protocol
		  		*/
		  		
		  		int getID(){
		  			return numThreads.fetch_add(1) % n;
		  		}
		  		
		  		void getTicket(int id){
		  			_turn[id] = _number.fetch_add(1);
		  		}
		  		
		  		void wait(int id){
		  			while(_turn[id] != _next){
		  				this_thread::sleep_for(interval);
		  			}
		  		}
		  		
		  		void criticalBegin(){
		  			return;
		  		}
		  		
		  		void criticalEnd(){
		  			_next += 1;
		  		}
		  		«ENDIF»
		  	};
		
			template<typename T>
			struct ModelIndex<T, ModelRoot> {
				static const std::list<T*>& instances(const ModelRoot* modelRoot)
				{
					return T::_instances;
				}
			};
			}
		}
	'''
}