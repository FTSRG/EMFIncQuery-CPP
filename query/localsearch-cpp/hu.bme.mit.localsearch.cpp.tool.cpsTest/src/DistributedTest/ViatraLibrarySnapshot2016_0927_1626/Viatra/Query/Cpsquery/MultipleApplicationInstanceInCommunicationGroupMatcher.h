#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/HostCommunicationMatcher.h"
#include "Viatra/Query/Cpsquery/MultipleApplicationInstanceInCommunicationGroupMatch.h"
#include "Viatra/Query/Cpsquery/MultipleApplicationInstanceInCommunicationGroupQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class MultipleApplicationInstanceInCommunicationGroupMatcher {
public:
	MultipleApplicationInstanceInCommunicationGroupMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<MultipleApplicationInstanceInCommunicationGroupMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<MultipleApplicationInstanceInCommunicationGroupMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_1664234907(_model,  _context);
			for(auto&& reachableAppInstance_0__reachableHosts_0__source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto reachableAppInstance_0__reachableHosts_0__source_0 = reachableAppInstance_0__reachableHosts_0__source;
					if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto reachableAppInstance_0__reachableHosts_0__source_1 = reachableAppInstance_0__reachableHosts_0__source_0;
						if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source_1->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
							auto reachableAppInstance_0__reachableHosts_0__source_2 = reachableAppInstance_0__reachableHosts_0__source_1;
							if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source_2->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
								auto reachableAppInstance_0__reachableHosts_0__source_3 = reachableAppInstance_0__reachableHosts_0__source_2;
								for(auto&& reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
									if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->allocatedTo)>::check(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->allocatedTo)) {
										auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->allocatedTo;
										if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
											auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance;
											if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
												auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance;
												if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
													auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0;
													if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
														auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1;
														if(transitive_closure_check(matcher_1664234907, &HostCommunicationMatch::toHost, reachableAppInstance_0__reachableHosts_0__source_3, reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_0)) {
															for(auto&& reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
																if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type)>::check(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type)) {
																	auto reachableAppInstance_0__appTypeInstanceAndHost_1__app = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type;
																	if(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2->type == reachableAppInstance_0__appTypeInstanceAndHost_1__app) {
																		if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																			auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__app;
																			if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																				auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance;
																				if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																					auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0;
																					if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->allocatedTo == reachableAppInstance_0__reachableHosts_0__source_3) {
																						if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app_0->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																							auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__app_0;
																							if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																								auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1;
																								if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 != reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2){
																									::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch match;
																									match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(reachableAppInstance_0__reachableHosts_0__source_3);
																									match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(reachableAppInstance_0__appTypeInstanceAndHost_1__app_1);
																									
																									matches.insert(match);
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance;
					if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_1 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0;
						if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_1->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
							auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_2 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_1;
							if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_2->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
								auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_3 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_2;
								if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_3->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
									auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_4 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_3;
									for(auto&& reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance : reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_4->applications) {
										if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
											auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance;
											if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
												auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0;
												if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
													auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1;
													for(auto&& reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
														if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type)>::check(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type)) {
															auto reachableAppInstance_0__appTypeInstanceAndHost_1__app = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->type;
															if(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2->type == reachableAppInstance_0__appTypeInstanceAndHost_1__app) {
																if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																	auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__app;
																	if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																		auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance;
																		if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																			auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0;
																			if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->allocatedTo == reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_4) {
																				if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app_0->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																					auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__app_0;
																					if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																						auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1;
																						if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 != reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2){
																							::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch match;
																							match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(reachableAppInstance_0__appTypeInstanceAndHost_1__app_1);
																							match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_4);
																							
																							matches.insert(match);
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_1304831556(_model,  _context);
			for(auto&& reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance;
					if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_0;
						if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_1->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
							auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_2 = reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_1;
							if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_2->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
								auto reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_3 = reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_2;
								for(auto&& reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
									if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type)>::check(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type)) {
										auto reachableAppInstance_0__appTypeInstanceAndHost_1__app = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type;
										if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
											auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance;
											if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
												auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0;
												if(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->allocatedTo == reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_3) {
													if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
														auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__app;
														if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
															auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1;
															if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app_0->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__app_0;
																for(auto&& reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
																	if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo)>::check(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo)) {
																		auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo;
																		if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
																			auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance;
																			if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																				auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance;
																				if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->type == reachableAppInstance_0__appTypeInstanceAndHost_1__app_1) {
																					if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																						auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0;
																						if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																							auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1;
																							if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 != reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2){
																								if(transitive_closure_check(matcher_1304831556, &HostCommunicationMatch::toHost, reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_3, reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0)) {
																									::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch match;
																									match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(reachableAppInstance_0__appTypeInstanceAndHost_1__app_1);
																									match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(reachableAppInstance_0__appTypeInstanceAndHost_1__hostInstance_3);
																									
																									matches.insert(match);
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_656960232(_model,  _context);
			HostCommunicationMatcher<ModelRoot> matcher_742211966(_model,  _context);
			for(auto&& reachableAppInstance_0__reachableHosts_0__source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto reachableAppInstance_0__reachableHosts_0__source_0 = reachableAppInstance_0__reachableHosts_0__source;
					if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto reachableAppInstance_0__reachableHosts_0__source_1 = reachableAppInstance_0__reachableHosts_0__source_0;
						if(_classHelper->is_super_type(reachableAppInstance_0__reachableHosts_0__source_1->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
							auto reachableAppInstance_0__reachableHosts_0__source_2 = reachableAppInstance_0__reachableHosts_0__source_1;
							for(auto&& reachableAppInstance_0__reachableHosts_0__target : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
								if(transitive_closure_check(matcher_656960232, &HostCommunicationMatch::toHost, reachableAppInstance_0__reachableHosts_0__source_2, reachableAppInstance_0__reachableHosts_0__target)) {
									for(auto&& reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
										if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type)>::check(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type)) {
											auto reachableAppInstance_0__appTypeInstanceAndHost_1__app = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->type;
											if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
												auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance;
												if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
													auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_0;
													if(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->allocatedTo == reachableAppInstance_0__reachableHosts_0__target) {
														if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
															auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_0 = reachableAppInstance_0__appTypeInstanceAndHost_1__app;
															if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																auto reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_1;
																if(_classHelper->is_super_type(reachableAppInstance_0__appTypeInstanceAndHost_1__app_0->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
																	auto reachableAppInstance_0__appTypeInstanceAndHost_1__app_1 = reachableAppInstance_0__appTypeInstanceAndHost_1__app_0;
																	for(auto&& reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
																		if(!::Viatra::Query::Util::IsNull<decltype(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo)>::check(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo)) {
																			auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->allocatedTo;
																			if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
																				auto reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance;
																				if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																					auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance;
																					if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->type == reachableAppInstance_0__appTypeInstanceAndHost_1__app_1) {
																						if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																							auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_0;
																							if(_classHelper->is_super_type(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
																								auto reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 = reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_1;
																								if(reachableAppInstance_1__appTypeInstanceAndHost_1__appInstance_2 != reachableAppInstance_0__appTypeInstanceAndHost_1__appInstance_2){
																									if(transitive_closure_check(matcher_742211966, &HostCommunicationMatch::toHost, reachableAppInstance_0__reachableHosts_0__source_2, reachableAppInstance_1__appTypeInstanceAndHost_1__hostInstance_0)) {
																										::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch match;
																										match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(reachableAppInstance_0__reachableHosts_0__source_2);
																										match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(reachableAppInstance_0__appTypeInstanceAndHost_1__app_1);
																										
																										matches.insert(match);
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
	
		return matches;
	}
	
private:
	template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
	bool transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

template<class ModelRoot>
template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
inline bool MultipleApplicationInstanceInCommunicationGroupMatcher<ModelRoot>::transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const {
	std::unordered_set<SrcType> sourcesToEvaluate; 
	sourcesToEvaluate.insert(src);
	std::unordered_set<SrcType> sourceEvaluated; 

	do{
		auto it = sourcesToEvaluate.begin();
		auto currentSrc = *it;
		sourcesToEvaluate.erase(it);
		sourceEvaluated.insert(currentSrc);

		auto matches = matcher.matches(currentSrc);
		for(auto& match : matches)
		{
			auto foundTarget = match.*trgMember;

			if(trg == foundTarget) return true;
			else if( sourceEvaluated.count(foundTarget) == 0)
				sourcesToEvaluate.insert(foundTarget);
		}
	} while(!sourcesToEvaluate.empty());
	return false;
}

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCHER_H_ */
