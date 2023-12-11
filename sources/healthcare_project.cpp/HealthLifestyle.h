// HealthLifestyle.h ÆÄÀÏ

#ifndef HEALTH_LIFESTYLE_H
#define HEALTH_LIFESTYLE_H

#include <iostream>
#include <vector>

using namespace std;

class HealthRecommendation {
 public:
  void brainHealthAdvice();
  void skinHealthAdvice();
  void neckHealthAdvice();
  void stomachHealthAdvice();
  void liverHealthAdvice();
  void intestineHealthAdvice();
  void femaleHealthAdvice();
  void maleHealthAdvice();  
  void boneHealthAdvice();  
};

class LifestyleSurvey {
 public:
  void takeSurvey();
};

class HealthSurvey {
 public:
  void takeSurvey();
};

#endif /* HEALTH_LIFESTYLE_H */