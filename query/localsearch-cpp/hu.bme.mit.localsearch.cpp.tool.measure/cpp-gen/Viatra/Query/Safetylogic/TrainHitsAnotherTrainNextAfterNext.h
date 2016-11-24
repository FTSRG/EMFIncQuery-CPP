#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_H_

#include <map>
#include <string>
		
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextMatch.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextMatcher.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrainNextAfterNext;

	class TrainHitsAnotherTrainNextAfterNext {
	public:
		template<typename ModelRoot>
		using RootedQuery = RootedTrainHitsAnotherTrainNextAfterNext<ModelRoot>;
		
		using Match = TrainHitsAnotherTrainNextAfterNextMatch;
		using QueryGroup = SafetylogicQueryGroup;
		
		struct BindInfo{ std::map<int, std::string> encodedFrameVector; };
		
		struct Bind{
		};
		
		struct NoBind{
			using QueryClass = TrainHitsAnotherTrainNextAfterNext;
			static constexpr int queryID = 13;
			static BindInfo BuildFrames(){
				std::map<int, std::string> encodedFrames;
				
				{
					TrainHitsAnotherTrainNextAfterNextFrame_0 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_0Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[0] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_1 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_1Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[1] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_2 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_2Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[2] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_3 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_3Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[3] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_4 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_4Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[4] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_5 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_5Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[5] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_6 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_6Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[6] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_7 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_7Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[7] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_8 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_8Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[8] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_9 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_9Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[9] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_10 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_10Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[10] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_11 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_11Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[11] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_12 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_12Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[12] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_13 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_13Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[13] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_14 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_14Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[14] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_15 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_15Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[15] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_16 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_16Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[16] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_17 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_17Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[17] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_18 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_18Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[18] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_19 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_19Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[19] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_20 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_20Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[20] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_21 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_21Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[21] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_22 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_22Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[22] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_23 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_23Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[23] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_24 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_24Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[24] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_25 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_25Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[25] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_26 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_26Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[26] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_27 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_27Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[27] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_28 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_28Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[28] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_29 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_29Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[29] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_30 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_30Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[30] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_31 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_31Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[31] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_32 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_32Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[32] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_33 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_33Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[33] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_34 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_34Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[34] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_35 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_35Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[35] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_36 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_36Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[36] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_37 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_37Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[37] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_38 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_38Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[38] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_39 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_39Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[39] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_40 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_40Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[40] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_41 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_41Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[41] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_42 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_42Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[42] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_43 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_43Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[43] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_44 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_44Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[44] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_45 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_45Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[45] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_46 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_46Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[46] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_47 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_47Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[47] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_48 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_48Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[48] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_49 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_49Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[49] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_50 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_50Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[50] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_51 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_51Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[51] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_52 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_52Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[52] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_53 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_53Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[53] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_54 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_54Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[54] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_55 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_55Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[55] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_56 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_56Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[56] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_57 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_57Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[57] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_58 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_58Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[58] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_59 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_59Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[59] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_60 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_60Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[60] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_61 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_61Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[61] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_62 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_62Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[62] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_63 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_63Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[63] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_64 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_64Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[64] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_65 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_65Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[65] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_66 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_66Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[66] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_67 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_67Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[67] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_68 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_68Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[68] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_69 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_69Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[69] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_70 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_70Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[70] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_71 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_71Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[71] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_72 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_72Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[72] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_73 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_73Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[73] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_74 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_74Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[74] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_75 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_75Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[75] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_76 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_76Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[76] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_77 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_77Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[77] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_78 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_78Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[78] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_79 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_79Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[79] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_80 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_80Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[80] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_81 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_81Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[81] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_82 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_82Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[82] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_83 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_83Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[83] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_84 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_84Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[84] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_85 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_85Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[85] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_86 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_86Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[86] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_87 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_87Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[87] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_88 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_88Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[88] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_89 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_89Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[89] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_90 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_90Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[90] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_91 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_91Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[91] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_92 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_92Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[92] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_93 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_93Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[93] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_94 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_94Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[94] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_95 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_95Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[95] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_96 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_96Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[96] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_97 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_97Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[97] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_98 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_98Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[98] = frameVector.SerializeAsString();
				}
				{
					TrainHitsAnotherTrainNextAfterNextFrame_99 frame;
					TrainHitsAnotherTrainNextAfterNextFrame_99Vector frameVector;
					frameVector.push_back(frame);
					encodedFrames[99] = frameVector.SerializeAsString();
				}
				
				return BindInfo{std::move(encodedFrames)};
			}
		};
	};	
	
	template<class ModelRootParam>
	class RootedTrainHitsAnotherTrainNextAfterNext {
	public:
		using BindInfo = TrainHitsAnotherTrainNextAfterNext::BindInfo;
		using ModelRoot = ModelRootParam;
		using Matcher = TrainHitsAnotherTrainNextAfterNextMatcher<ModelRoot>;
		using QuerySpecification = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>;
		using Match = TrainHitsAnotherTrainNextAfterNextMatch;
		using QueryGroup = SafetylogicQueryGroup;
	};
			

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_H_ */
