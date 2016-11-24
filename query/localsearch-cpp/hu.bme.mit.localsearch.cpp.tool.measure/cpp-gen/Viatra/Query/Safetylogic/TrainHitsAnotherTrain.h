#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainMatch.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainMatcher.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrain;

	class TrainHitsAnotherTrain {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedTrainHitsAnotherTrain<ModelRoot>;
		
		using Match = TrainHitsAnotherTrainMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = TrainHitsAnotherTrain;
			static constexpr int queryID = 17;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					TrainHitsAnotherTrainFrame_0 frame;
					TrainHitsAnotherTrainFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_1 frame;
					TrainHitsAnotherTrainFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_2 frame;
					TrainHitsAnotherTrainFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_3 frame;
					TrainHitsAnotherTrainFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_4 frame;
					TrainHitsAnotherTrainFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_5 frame;
					TrainHitsAnotherTrainFrame_5Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[5] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_6 frame;
					TrainHitsAnotherTrainFrame_6Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[6] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_7 frame;
					TrainHitsAnotherTrainFrame_7Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[7] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_8 frame;
					TrainHitsAnotherTrainFrame_8Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[8] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_9 frame;
					TrainHitsAnotherTrainFrame_9Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[9] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_10 frame;
					TrainHitsAnotherTrainFrame_10Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[10] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_11 frame;
					TrainHitsAnotherTrainFrame_11Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[11] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_12 frame;
					TrainHitsAnotherTrainFrame_12Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[12] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_13 frame;
					TrainHitsAnotherTrainFrame_13Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[13] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_14 frame;
					TrainHitsAnotherTrainFrame_14Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[14] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_15 frame;
					TrainHitsAnotherTrainFrame_15Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[15] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_16 frame;
					TrainHitsAnotherTrainFrame_16Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[16] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_17 frame;
					TrainHitsAnotherTrainFrame_17Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[17] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_18 frame;
					TrainHitsAnotherTrainFrame_18Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[18] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_19 frame;
					TrainHitsAnotherTrainFrame_19Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[19] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_20 frame;
					TrainHitsAnotherTrainFrame_20Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[20] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_21 frame;
					TrainHitsAnotherTrainFrame_21Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[21] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_22 frame;
					TrainHitsAnotherTrainFrame_22Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[22] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_23 frame;
					TrainHitsAnotherTrainFrame_23Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[23] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_24 frame;
					TrainHitsAnotherTrainFrame_24Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[24] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_25 frame;
					TrainHitsAnotherTrainFrame_25Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[25] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_26 frame;
					TrainHitsAnotherTrainFrame_26Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[26] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_27 frame;
					TrainHitsAnotherTrainFrame_27Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[27] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_28 frame;
					TrainHitsAnotherTrainFrame_28Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[28] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_29 frame;
					TrainHitsAnotherTrainFrame_29Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[29] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_30 frame;
					TrainHitsAnotherTrainFrame_30Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[30] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_31 frame;
					TrainHitsAnotherTrainFrame_31Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[31] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_32 frame;
					TrainHitsAnotherTrainFrame_32Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[32] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_33 frame;
					TrainHitsAnotherTrainFrame_33Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[33] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_34 frame;
					TrainHitsAnotherTrainFrame_34Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[34] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_35 frame;
					TrainHitsAnotherTrainFrame_35Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[35] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_36 frame;
					TrainHitsAnotherTrainFrame_36Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[36] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_37 frame;
					TrainHitsAnotherTrainFrame_37Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[37] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_38 frame;
					TrainHitsAnotherTrainFrame_38Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[38] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_39 frame;
					TrainHitsAnotherTrainFrame_39Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[39] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_40 frame;
					TrainHitsAnotherTrainFrame_40Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[40] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_41 frame;
					TrainHitsAnotherTrainFrame_41Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[41] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_42 frame;
					TrainHitsAnotherTrainFrame_42Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[42] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_43 frame;
					TrainHitsAnotherTrainFrame_43Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[43] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_44 frame;
					TrainHitsAnotherTrainFrame_44Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[44] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_45 frame;
					TrainHitsAnotherTrainFrame_45Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[45] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_46 frame;
					TrainHitsAnotherTrainFrame_46Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[46] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_47 frame;
					TrainHitsAnotherTrainFrame_47Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[47] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_48 frame;
					TrainHitsAnotherTrainFrame_48Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[48] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_49 frame;
					TrainHitsAnotherTrainFrame_49Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[49] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_50 frame;
					TrainHitsAnotherTrainFrame_50Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[50] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_51 frame;
					TrainHitsAnotherTrainFrame_51Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[51] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_52 frame;
					TrainHitsAnotherTrainFrame_52Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[52] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_53 frame;
					TrainHitsAnotherTrainFrame_53Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[53] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_54 frame;
					TrainHitsAnotherTrainFrame_54Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[54] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_55 frame;
					TrainHitsAnotherTrainFrame_55Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[55] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_56 frame;
					TrainHitsAnotherTrainFrame_56Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[56] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_57 frame;
					TrainHitsAnotherTrainFrame_57Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[57] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_58 frame;
					TrainHitsAnotherTrainFrame_58Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[58] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_59 frame;
					TrainHitsAnotherTrainFrame_59Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[59] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_60 frame;
					TrainHitsAnotherTrainFrame_60Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[60] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_61 frame;
					TrainHitsAnotherTrainFrame_61Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[61] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_62 frame;
					TrainHitsAnotherTrainFrame_62Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[62] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_63 frame;
					TrainHitsAnotherTrainFrame_63Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[63] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_64 frame;
					TrainHitsAnotherTrainFrame_64Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[64] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_65 frame;
					TrainHitsAnotherTrainFrame_65Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[65] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_66 frame;
					TrainHitsAnotherTrainFrame_66Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[66] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_67 frame;
					TrainHitsAnotherTrainFrame_67Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[67] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_68 frame;
					TrainHitsAnotherTrainFrame_68Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[68] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_69 frame;
					TrainHitsAnotherTrainFrame_69Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[69] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_70 frame;
					TrainHitsAnotherTrainFrame_70Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[70] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_71 frame;
					TrainHitsAnotherTrainFrame_71Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[71] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_72 frame;
					TrainHitsAnotherTrainFrame_72Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[72] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_73 frame;
					TrainHitsAnotherTrainFrame_73Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[73] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_74 frame;
					TrainHitsAnotherTrainFrame_74Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[74] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_75 frame;
					TrainHitsAnotherTrainFrame_75Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[75] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_76 frame;
					TrainHitsAnotherTrainFrame_76Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[76] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_77 frame;
					TrainHitsAnotherTrainFrame_77Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[77] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_78 frame;
					TrainHitsAnotherTrainFrame_78Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[78] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_79 frame;
					TrainHitsAnotherTrainFrame_79Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[79] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_80 frame;
					TrainHitsAnotherTrainFrame_80Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[80] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_81 frame;
					TrainHitsAnotherTrainFrame_81Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[81] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_82 frame;
					TrainHitsAnotherTrainFrame_82Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[82] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_83 frame;
					TrainHitsAnotherTrainFrame_83Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[83] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_84 frame;
					TrainHitsAnotherTrainFrame_84Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[84] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_85 frame;
					TrainHitsAnotherTrainFrame_85Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[85] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_86 frame;
					TrainHitsAnotherTrainFrame_86Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[86] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_87 frame;
					TrainHitsAnotherTrainFrame_87Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[87] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_88 frame;
					TrainHitsAnotherTrainFrame_88Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[88] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_89 frame;
					TrainHitsAnotherTrainFrame_89Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[89] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_90 frame;
					TrainHitsAnotherTrainFrame_90Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[90] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_91 frame;
					TrainHitsAnotherTrainFrame_91Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[91] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_92 frame;
					TrainHitsAnotherTrainFrame_92Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[92] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_93 frame;
					TrainHitsAnotherTrainFrame_93Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[93] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_94 frame;
					TrainHitsAnotherTrainFrame_94Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[94] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_95 frame;
					TrainHitsAnotherTrainFrame_95Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[95] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_96 frame;
					TrainHitsAnotherTrainFrame_96Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[96] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_97 frame;
					TrainHitsAnotherTrainFrame_97Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[97] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_98 frame;
					TrainHitsAnotherTrainFrame_98Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[98] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_99 frame;
					TrainHitsAnotherTrainFrame_99Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[99] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_100 frame;
					TrainHitsAnotherTrainFrame_100Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[100] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_101 frame;
					TrainHitsAnotherTrainFrame_101Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[101] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_102 frame;
					TrainHitsAnotherTrainFrame_102Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[102] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_103 frame;
					TrainHitsAnotherTrainFrame_103Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[103] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_104 frame;
					TrainHitsAnotherTrainFrame_104Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[104] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_105 frame;
					TrainHitsAnotherTrainFrame_105Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[105] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_106 frame;
					TrainHitsAnotherTrainFrame_106Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[106] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_107 frame;
					TrainHitsAnotherTrainFrame_107Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[107] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_108 frame;
					TrainHitsAnotherTrainFrame_108Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[108] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_109 frame;
					TrainHitsAnotherTrainFrame_109Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[109] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_110 frame;
					TrainHitsAnotherTrainFrame_110Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[110] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_111 frame;
					TrainHitsAnotherTrainFrame_111Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[111] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_112 frame;
					TrainHitsAnotherTrainFrame_112Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[112] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_113 frame;
					TrainHitsAnotherTrainFrame_113Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[113] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainFrame_114 frame;
					TrainHitsAnotherTrainFrame_114Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[114] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrain {
	public:
		using BindInfo = TrainHitsAnotherTrain::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = TrainHitsAnotherTrainMatcher<ModelRoot>;
		using QuerySpecification = TrainHitsAnotherTrainQuerySpecification<ModelRoot>;
		using Match = TrainHitsAnotherTrainMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_H_ */
