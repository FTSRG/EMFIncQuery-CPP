#pragma once


namespace Viatra {
	namespace Query {
		namespace Util {

			template<typename T, typename Set>
			class BufferedSet
			{
				Set readySet;
				Set set;
				std::atomic<bool> finished = false;

				void add() {  }
				void finish() { finished = true; }

				template<typename Action>
				void process(Action callback)
				{}
			
			}
		}
	}
}