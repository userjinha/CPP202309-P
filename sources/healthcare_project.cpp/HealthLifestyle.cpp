#include "HealthLifestyle.h"

// ���� ������ ������ ���� �ǰ� ���� �� ���� ��õ ��� �Լ�
void HealthRecommendation::healthAdvice(const string& part) {
  displayAdvice(part);
}

// ������ ���� ��Ȱ ���� �� ���� ��õ���ִ� ��� �Լ�
void HealthRecommendation::displayAdvice(const std::string& part) const {
  std::cout << "--" << part << " �ǰ�--" << std::endl;
  std::cout << "1. ��Ȱ ����\n2. ��õ ����\n3. �����ϱ�\n";
  int choice;
  std::cin >> choice;

  if (adviceMap.find(part) != adviceMap.end()) {
    switch (choice) {
      case 1:
        std::cout << "--��õ ��Ȱ ����--\n" << adviceMap.at(part).first << std::endl;
        break;
      case 2:
        std::cout << "--��õ ����--\n" << adviceMap.at(part).second << std::endl;
        break;
      case 3:
        std::cout << "�����մϴ�." << std::endl;
        break;
      default:
        std::cout << "��ȿ���� ���� �����Դϴ�." << std::endl;
        break;
    }
  } else if (part == "stomach" || part == "liver" || part == "intestine") {
    // ��, ��, �忡 �ش��ϴ� �κ��� ó��
    switch (choice) {
      case 1:
        std::cout << "--��Ȱ ����--\n"
                  << adviceMap.at(" stomach").first << std::endl;
        break;
      case 2:
        std::cout << "--����--\n"
                  << adviceMap.at(" stomach").second << std::endl;
        break;
      case 3:
        std::cout << "�����մϴ�." << std::endl;
        break;
      default:
        std::cout << "��ȿ���� ���� �����Դϴ�." << std::endl;
        break;
    }
  } else {
    std::cout << "��ȿ���� ���� �����Դϴ�." << std::endl;
  }
}


// ��Ȱ���� �������� ��� �Լ�
void LifestyleSurvey::takeSurvey() {
  int exerciseFreq, sleepHours, breakfastFreq;

  cout << "----��Ȱ���� ��������----" << endl;

  cout << "1. ��� ��� ���� �Ͻó���? (1: ��, 2: ���� ����): ";
  cin >> exerciseFreq;

  cout << "2. ��� ���� ��ð� ���� �ڳ���? (1: 5�ð� �̸�, 2: 6�ð�~9�ð�, "
          "3: 10�ð� �̻�): ";
  cin >> sleepHours;

  cout << "3. ��ħ�Ļ縦 ���� �Ͻó���? (1: ����, 2: ���� �� ����): ";
  cin >> breakfastFreq;

  // ���� ��� �κ�
  cout << " ==����==" << endl;
  if (exerciseFreq == 2) {
    if (exerciseType == 1) {
      cout << "����� ��� ��õ�մϴ�." << endl;
      cout << "�ȱ�, ����, ����, ������Ÿ�� ���� ��� �����մϴ�." << endl;
    } else if (exerciseType == 2) {
      cout << "�ٷ� ��� ��õ�մϴ�." << endl;
      cout << "����Ʈ, ���帮��Ʈ, ��ġ ������, ü���� Ǫ�þ� ���� ��� "
              "�����մϴ�."
           << endl;
    }
  }

  if (sleepHours == 1) {
    cout << "������ �������� �ּ� 6�ð��� ������ �����ϴ�." << endl;
    cout << "������ ������ ��� ������ ����, ���, ����, ������ ��å, �� "
            "���ñ� ���� ��õ�մϴ�."
         << endl;
  } else if (sleepHours == 3) {
    cout << "�Ϸ翡 10�ð� �̻� �ڴ� ���� ���� �ʽ��ϴ�." << endl;
    cout << "���� ���� �� ��� ��Ʈ����, ������, �๰ ���ۿ� ���� ������ �� �� "
            "�ֽ��ϴ�."
         << endl;
  }

  if (breakfastFreq == 2) {
    cout << "��ħ�Ļ�� ���߷�/���� ����, ������ ����, ü�� ����, �鿪�� "
            "����, ���� ���� � ������ �˴ϴ�."
         << endl;
    cout << "��� �佺Ʈ, �ܹ��� ����ũ, �׸� ���Ʈ, ��Ʈ�� ���� ������ "
            "��ħ�Ļ�� ��õ�մϴ�."
         << endl;
  }
}



// ���� �ΰ� ������ ������ ���� �����ϱ� ���� �Լ�
void HealthSurvey::takeSurvey() {
  int diseaseChoice;

  cout << "----�� ������ �ｺ�ɾ�----" << endl << endl;

  // ����ڰ� �����ϱ⸦ ������ ������ �ݺ�
  do {
    cout << "1. ���� ���� �ΰ� �ֳ���? (1: ��, 2: �ƴϿ� 3. �����ϱ�) ";
    cin >> diseaseChoice;

    HealthRecommendation recommendation;

    if (diseaseChoice == 1) {
      int specificDiseaseChoice;
      cout << "1-1. ��ü������ � ������ �̻��� �����Ű���?" << endl;
      vector<string> bodyParts = {
          "��",     "�Ǻ�",   "��", "����(1.��, 2.��, 3.��)",
          "���ı�", "�񴢱�", "��"};

      for (int i = 0; i < bodyParts.size(); ++i) {
        cout << i + 1 << ") " << bodyParts[i] << "\n";
      }
      cin >> specificDiseaseChoice;

      if (specificDiseaseChoice >= 1 &&
          specificDiseaseChoice <= bodyParts.size()) {
        if (specificDiseaseChoice !=
            4) {  // "����(1.��, 2.��, 3.��)"�� �ƴ� ���
          cout << bodyParts[specificDiseaseChoice-1 ]
               << " �ǰ��� ���� �����Դϴ�." << std::endl;
          recommendation.healthAdvice(bodyParts[specificDiseaseChoice-1]);
        } else {  // "����(1.��, 2.��, 3.��)"�� ���
          int abdomenChoice;
          do {
            cout << "1. ��   2. ��   3. �� ";
            cin >> abdomenChoice;
            if (abdomenChoice >= 1 && abdomenChoice <= 3) {
              switch (abdomenChoice) {
                case 1:
                  cout << "�� �ǰ��� ���� �����Դϴ�." << std::endl;
                  recommendation.healthAdvice("��");
                  break;
                case 2:
                  cout << "�� �ǰ��� ���� �����Դϴ�." << std::endl;
                  recommendation.healthAdvice("��");
                  break;
                case 3:
                  cout << "�� �ǰ��� ���� �����Դϴ�." << std::endl;
                  recommendation.healthAdvice("��");
                  break;
              }
              break;
            } else {
              cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �������ּ���." << endl;
              std::cin.clear();  // clear the error flag
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                              '\n');  // discard the input buffer
            }
          } while (true);
        }
      } else {
        std::cout << "��ȿ���� ���� �����Դϴ�." << std::endl;
      }
    } 
    else if (diseaseChoice == 2) {
      std::cout << std::endl;
      std::cout << "��Ȱ���� ��������� �̵��մϴ�." << std::endl;
      LifestyleSurvey lifestyleSurvey;
      lifestyleSurvey.takeSurvey();
      break;
    } 
    
    else {
      cout <<"�����մϴ�" << endl;
      break;
    }

   
  } while (true);  // �����ϱ⸦ ������ ������ �ݺ�
}
