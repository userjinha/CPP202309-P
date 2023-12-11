#include "HealthLifestyle.h"

void HealthRecommendation::brainHealthAdvice() {
  cout << "�� �ǰ��� ���� �����Դϴ�:" << endl;
}
void HealthRecommendation::skinHealthAdvice() {
  cout << "�Ǻ� �ǰ��� ���� ����" << endl;
}
void HealthRecommendation::neckHealthAdvice() {
  cout << "�� �ǰ��� ���� ����" << endl;
}
void HealthRecommendation::stomachHealthAdvice() {
  cout << "---�� �ǰ��� ���� ����---" << endl;
  // �� �ǰ��� ���� ���� ���
}

void HealthRecommendation::liverHealthAdvice() {
  cout << "---�� �ǰ��� ���� ����---" << endl;
  // �� �ǰ��� ���� ���� ���
}

void HealthRecommendation::intestineHealthAdvice() {
  cout << "---�� �ǰ��� ���� ����---" << endl;
  // �� �ǰ��� ���� ���� ���
}
void HealthRecommendation::femaleHealthAdvice() {
  cout << "���ı� �ǰ��� ���� ����" << endl;
}
void HealthRecommendation::maleHealthAdvice() {
  cout << " �񴢱� �ǰ��� ���� ����" << endl;
}
void HealthRecommendation::boneHealthAdvice() {
  cout << "�� �ǰ��� ���� ����" << endl;
}


// ������ HealthRecommendation�� �Լ��� ����

void LifestyleSurvey::takeSurvey() {
    int exerciseFreq, sleepHours, breakfastFreq;

    cout << "----��Ȱ���� ��������----" << endl;
    cout << "1. ��� ��� ���� �Ͻó���? (1: ��, 2: ���� ����): ";
    cin >> exerciseFreq;

    if (exerciseFreq == 1 || exerciseFreq == 2) {
      cout << "������ �������� �����Ͽ� �ּ� 5��, �Ϸ翡 30�� �̻��� ������ "
              "�Ǵ� �߰��� ��� �����մϴ�."
           << endl;
      cout << "�����Ͽ� �ּ� 3��, �Ϸ翡 20�� �̻��� ���� ��� �����մϴ�."
           << endl;
    }

    int exerciseType;
    if (exerciseFreq == 2) {
      cout << "1. �׳� �   2. ���� Ű���: ";
      cin >> exerciseType;

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

    cout << "2. ��� ���� ��ð� ���� �ڳ���? (1: 5�ð� �̸�, 2: 6�ð�~9�ð�, "
            "3: 10�ð� �̻�): ";
    cin >> sleepHours;

    if (sleepHours == 1) {
      cout << "������ �������� �ּ� 6�ð��� ������ �����ϴ�." << endl;
      cout << "������ ���� �ʴ´ٸ� ������ ����, ���, ����, ������ ��å, �� "
              "���ñ� ���� ��õ�մϴ�."
           << endl;
    } else if (sleepHours == 3) {
      cout << "�Ϸ翡 10�ð� �̻� �ڴ� ���� ���� �ʽ��ϴ�." << endl;
      cout << "���� ���� �� ��� ��Ʈ����, ������, �๰ ���ۿ� ���� ������ �� "
              "�� �ֽ��ϴ�."
           << endl;
    }

    cout << "3. ��ħ�Ļ縦 ���� �Ͻó���? (1: ����, 2: ���� �� ����): ";
    cin >> breakfastFreq;

    if (breakfastFreq == 2) {
      cout << "��ħ�Ļ�� ���߷�/���� ����, ������ ����, ü�� ����, �鿪�� "
              "����, ���� ���� � ������ �˴ϴ�."
           << endl;
      cout << "��� �佺Ʈ, �ܹ��� ����ũ, �׸� ���Ʈ, ��Ʈ�� ���� ������ "
              "��ħ�Ļ�� ��õ�մϴ�."
           << endl;
    }
  }



void HealthSurvey::takeSurvey() {
    int diseaseChoice;
    cout << "----�� ������ �ｺ�ɾ�----" << endl;
    cout << endl;
    cout << "1. ���� ���� �ΰ� �ֳ���? (1: ��, 2: �ƴϿ�) ";
    cin >> diseaseChoice;

    HealthRecommendation recommendation;
    if (diseaseChoice == 1) {
      int specificDiseaseChoice;
      cout << "1-1. ��ü������ � ������ �̻��� �����Ű���?" << endl;
      vector<string> bodyParts = {
          "��",     "�Ǻ�",   "��", "����(1.��, 2.��, 3.��)",
          "���ı�", "�񴢱�", "��"};

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
          cout << " 1. ��   2. ��   3. �� ";
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
              cout << "��ȿ���� ���� �����Դϴ�." << endl;
              break;
          }
          break;

        case 5:
          recommendation.femaleHealthAdvice();
          break;
        case 6:
          recommendation.maleHealthAdvice();
          break;
        case 7:
          recommendation.boneHealthAdvice();
          break;

        default:
          cout << "��ȿ���� ���� �����Դϴ�." << endl;
      }

    }

    else if (diseaseChoice == 2) {
      cout << endl;
      cout << "��Ȱ���� ��������� �̵��մϴ�." << endl;
      LifestyleSurvey lifestyleSurvey;
      lifestyleSurvey.takeSurvey();
    } else {
      cout << "��ȿ���� ���� �����Դϴ�.";
    }
  }
 
