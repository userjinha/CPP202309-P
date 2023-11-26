#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HealthRecommendation {
 public:
  void brainHealthAdvice() { cout << "뇌 건강을 위한 조언입니다:" << endl; }
  void skinHealthAdvice() { cout << "피부 건강을 위한 관리" << endl; }
  void neckHealthAdvice() { cout << "목 건강을 위한 관리" << endl; }
  void stomachHealthAdvice() {
    cout << "---위 건강을 위한 조언---" << endl;
    // 위 건강을 위한 조언 출력
  }

  void liverHealthAdvice() {
    cout << "---간 건강을 위한 조언---" << endl;
    // 간 건강을 위한 조언 출력
  }

  void intestineHealthAdvice() {
    cout << "---장 건강을 위한 조언---" << endl;
    // 장 건강을 위한 조언 출력
  }
  void femaleHealthAdvice() { cout << "생식기 건강을 위한 관리" << endl; }
  void maleHealtheAdvice() { cout << " 비뇨기 건강을 위한 관리" << endl; }
  void boneHealthAdivice() { cout << "뼈 건강을 위한 관리" << endl; }
};

class LifestyleSurvey {
 public:
  void takeSurvey() {
    int exerciseFreq, sleepHours, breakfastFreq;

    cout << "----생활습관 설문조사----" << endl;
    cout << "1. 평소 운동을 자주 하시나요? (1: 예, 2: 거의 안함): ";
    cin >> exerciseFreq;

    if (exerciseFreq == 1 || exerciseFreq == 2) {
      cout << "성인을 기준으로 일주일에 최소 5번, 하루에 30분 이상의 저강도 "
              "또는 중강도 운동을 권장합니다."
           << endl;
      cout << "일주일에 최소 3일, 하루에 20분 이상의 고강도 운동을 권장합니다."
           << endl;
    }

    int exerciseType;
    if (exerciseFreq == 2) {
      cout << "1. 그냥 운동   2. 근육 키우기: ";
      cin >> exerciseType;

      if (exerciseType == 1) {
        cout << "유산소 운동을 추천합니다." << endl;
        cout << "걷기, 조깅, 수영, 자전거타기 등의 운동을 권장합니다." << endl;
      } else if (exerciseType == 2) {
        cout << "근력 운동을 추천합니다." << endl;
        cout << "스쿼트, 데드리프트, 벤치 프레스, 체인지 푸시업 등의 운동을 "
                "권장합니다."
             << endl;
      }
    }

    cout << "2. 평소 잠을 몇시간 정도 자나요? (1: 5시간 미만, 2: 6시간~9시간, "
            "3: 10시간 이상): ";
    cin >> sleepHours;

    if (sleepHours == 1) {
      cout << "성인을 기준으로 최소 6시간의 수면이 좋습니다." << endl;
      cout << "수면이 오지 않는다면 따뜻한 샤워, 명상, 독서, 느긋한 산책, 차 "
              "마시기 등을 추천합니다."
           << endl;
    } else if (sleepHours == 3) {
      cout << "하루에 10시간 이상 자는 것이 좋지 않습니다." << endl;
      cout << "잠을 많이 잘 경우 스트레스, 뇌졸중, 약물 부작용 등의 원인이 될 "
              "수 있습니다."
           << endl;
    }

    cout << "3. 아침식사를 자주 하시나요? (1: 매일, 2: 거의 안 먹음): ";
    cin >> breakfastFreq;

    if (breakfastFreq == 2) {
      cout << "아침식사는 집중력/기억력 증진, 에너지 공급, 체중 감량, 면역력 "
              "증진, 혈당 감소 등에 도움이 됩니다."
           << endl;
      cout << "통밀 토스트, 단백질 쉐이크, 그릭 요거트, 오트밀 등을 간단한 "
              "아침식사로 추천합니다."
           << endl;
    }
  }
};

class HealthSurvey {
 public:
  void takeSurvey() {
    int diseaseChoice;
    cout << "----고객 맞춤형 헬스케어----"<<endl;
    cout << endl;
    cout << "1. 현재 병을 앓고 있나요? (1: 예, 2: 아니요) ";
    cin >> diseaseChoice;

    HealthRecommendation recommendation;
    if (diseaseChoice == 1) {
      int specificDiseaseChoice;
      cout << "1-1. 구체적으로 어떤 부위가 이상이 있으신가요?" << endl;
      vector<string> bodyParts = {
          "뇌",     "피부",   "목", "복부(1.위, 2.간, 3.장)",
          "생식기", "비뇨기", "뼈"};

      for (int i = 0; i < bodyParts.size(); ++i) {
        cout << i + 1 << ") " << bodyParts[i] << " ";
      }
      cin >> specificDiseaseChoice;

      switch (specificDiseaseChoice) {
        case 1:
          recommendation.brainHealthAdvice();
          break;
        case 2:
          recommendation.skinHealthAdvice();
          break;
        case 3:
          recommendation.neckHealthAdvice();
          break;

        case 4:
          int abdomenChoice;
          cout << " 1. 위   2. 간   3. 장 ";
          cin >> abdomenChoice;
          switch (abdomenChoice) {
            case 1:
              recommendation.stomachHealthAdvice();
              break;
            case 2:
              recommendation.liverHealthAdvice();
              break;
            case 3:
              recommendation.intestineHealthAdvice();
              break;
            default:
              cout << "유효하지 않은 선택입니다." << endl;
              break;
          }

        case 5:
          recommendation.femaleHealthAdvice();
          break;
        case 6:
          recommendation.maleHealtheAdvice();
          break;
        case 7:
          recommendation.boneHealthAdivice();
          break;

<<<<<<< HEAD
        else if (diseaseChoice == 2) {

            cout << "��Ȱ���� ��������� �̵��մϴ�." << endl;
            LifestyleSurvey lifestyleSurvey;
            lifestyleSurvey.takeSurvey();
        }
        else {
            cout << "��ȿ���� ���� �����Դϴ�.";
        }
=======
        default:
          cout << "유효하지 않은 선택입니다." << endl;
      }
>>>>>>> 7c429701ebfabf83cff427a23d6c64902ed8692c
    }

    else if (diseaseChoice == 2) {
      cout << endl;
      cout << "생활습관 설문조사로 이동합니다." << endl;
      LifestyleSurvey lifestyleSurvey;
      lifestyleSurvey.takeSurvey();
    } else {
      cout << "유효하지 않은 선택입니다.";
    }
  }
};

<<<<<<< HEAD
 int main() {
    HealthSurvey takeSurvey();
    survey.takeSurvey(); // healthSurvey�� �������� ����
=======
int main() {
  HealthSurvey survey; 
  survey.takeSurvey();  // healthSurvey의 설문조사 시행
>>>>>>> 7c429701ebfabf83cff427a23d6c64902ed8692c

  return 0;
}
