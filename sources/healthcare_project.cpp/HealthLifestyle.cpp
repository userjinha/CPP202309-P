#include "HealthLifestyle.h"

// 병이 있을시 부위에 따른 건강 조언 및 음식 추천 출력 함수
void HealthRecommendation::healthAdvice(const string& part) {
  displayAdvice(part);
}

// 부위에 따른 생활 습관 및 음식 추천해주는 출력 함수
void HealthRecommendation::displayAdvice(const std::string& part) const {
  std::cout << "--" << part << " 건강--" << std::endl;
  std::cout << "1. 생활 습관\n2. 추천 음식\n3. 종료하기\n";
  int choice;
  std::cin >> choice;

  if (adviceMap.find(part) != adviceMap.end()) {
    switch (choice) {
      case 1:
        std::cout << "--추천 생활 습관--\n" << adviceMap.at(part).first << std::endl;
        break;
      case 2:
        std::cout << "--추천 음식--\n" << adviceMap.at(part).second << std::endl;
        break;
      case 3:
        std::cout << "종료합니다." << std::endl;
        break;
      default:
        std::cout << "유효하지 않은 선택입니다." << std::endl;
        break;
    }
  } else if (part == "stomach" || part == "liver" || part == "intestine") {
    // 위, 간, 장에 해당하는 부분을 처리
    switch (choice) {
      case 1:
        std::cout << "--생활 습관--\n"
                  << adviceMap.at(" stomach").first << std::endl;
        break;
      case 2:
        std::cout << "--음식--\n"
                  << adviceMap.at(" stomach").second << std::endl;
        break;
      case 3:
        std::cout << "종료합니다." << std::endl;
        break;
      default:
        std::cout << "유효하지 않은 선택입니다." << std::endl;
        break;
    }
  } else {
    std::cout << "유효하지 않은 선택입니다." << std::endl;
  }
}


// 생활습관 설문조사 출력 함수
void LifestyleSurvey::takeSurvey() {
  int exerciseFreq, sleepHours, breakfastFreq;

  cout << "----생활습관 설문조사----" << endl;

  cout << "1. 평소 운동을 자주 하시나요? (1: 예, 2: 거의 안함): ";
  cin >> exerciseFreq;

  cout << "2. 평소 잠을 몇시간 정도 자나요? (1: 5시간 미만, 2: 6시간~9시간, "
          "3: 10시간 이상): ";
  cin >> sleepHours;

  cout << "3. 아침식사를 자주 하시나요? (1: 매일, 2: 거의 안 먹음): ";
  cin >> breakfastFreq;

  // 조언 출력 부분
  cout << " ==조언==" << endl;
  if (exerciseFreq == 2) {
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

  if (sleepHours == 1) {
    cout << "성인을 기준으로 최소 6시간의 수면이 좋습니다." << endl;
    cout << "수면이 부족할 경우 따뜻한 샤워, 명상, 독서, 느긋한 산책, 차 "
            "마시기 등을 추천합니다."
         << endl;
  } else if (sleepHours == 3) {
    cout << "하루에 10시간 이상 자는 것이 좋지 않습니다." << endl;
    cout << "잠을 많이 잘 경우 스트레스, 뇌졸중, 약물 부작용 등의 원인이 될 수 "
            "있습니다."
         << endl;
  }

  if (breakfastFreq == 2) {
    cout << "아침식사는 집중력/기억력 증진, 에너지 공급, 체중 감량, 면역력 "
            "증진, 혈당 감소 등에 도움이 됩니다."
         << endl;
    cout << "통밀 토스트, 단백질 쉐이크, 그릭 요거트, 오트밀 등을 간단한 "
            "아침식사로 추천합니다."
         << endl;
  }
}



// 병을 앓고 있으면 부위에 따른 조언하기 위한 함수
void HealthSurvey::takeSurvey() {
  int diseaseChoice;

  cout << "----고객 맞춤형 헬스케어----" << endl << endl;

  // 사용자가 종료하기를 선택할 때까지 반복
  do {
    cout << "1. 현재 병을 앓고 있나요? (1: 예, 2: 아니요 3. 종료하기) ";
    cin >> diseaseChoice;

    HealthRecommendation recommendation;

    if (diseaseChoice == 1) {
      int specificDiseaseChoice;
      cout << "1-1. 구체적으로 어떤 부위가 이상이 있으신가요?" << endl;
      vector<string> bodyParts = {
          "뇌",     "피부",   "목", "복부(1.위, 2.간, 3.장)",
          "생식기", "비뇨기", "뼈"};

      for (int i = 0; i < bodyParts.size(); ++i) {
        cout << i + 1 << ") " << bodyParts[i] << "\n";
      }
      cin >> specificDiseaseChoice;

      if (specificDiseaseChoice >= 1 &&
          specificDiseaseChoice <= bodyParts.size()) {
        if (specificDiseaseChoice !=
            4) {  // "복부(1.위, 2.간, 3.장)"이 아닌 경우
          cout << bodyParts[specificDiseaseChoice-1 ]
               << " 건강에 대한 조언입니다." << std::endl;
          recommendation.healthAdvice(bodyParts[specificDiseaseChoice-1]);
        } else {  // "복부(1.위, 2.간, 3.장)"인 경우
          int abdomenChoice;
          do {
            cout << "1. 위   2. 간   3. 장 ";
            cin >> abdomenChoice;
            if (abdomenChoice >= 1 && abdomenChoice <= 3) {
              switch (abdomenChoice) {
                case 1:
                  cout << "위 건강에 대한 조언입니다." << std::endl;
                  recommendation.healthAdvice("위");
                  break;
                case 2:
                  cout << "간 건강에 대한 조언입니다." << std::endl;
                  recommendation.healthAdvice("간");
                  break;
                case 3:
                  cout << "장 건강에 대한 조언입니다." << std::endl;
                  recommendation.healthAdvice("장");
                  break;
              }
              break;
            } else {
              cout << "유효하지 않은 선택입니다. 다시 선택해주세요." << endl;
              std::cin.clear();  // clear the error flag
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                              '\n');  // discard the input buffer
            }
          } while (true);
        }
      } else {
        std::cout << "유효하지 않은 선택입니다." << std::endl;
      }
    } 
    else if (diseaseChoice == 2) {
      std::cout << std::endl;
      std::cout << "생활습관 설문조사로 이동합니다." << std::endl;
      LifestyleSurvey lifestyleSurvey;
      lifestyleSurvey.takeSurvey();
      break;
    } 
    
    else {
      cout <<"종료합니다" << endl;
      break;
    }

   
  } while (true);  // 종료하기를 선택할 때까지 반복
}
