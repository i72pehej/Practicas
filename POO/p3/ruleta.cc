//Ruleta.cc
//Methods of class Ruleta.

#include "ruleta.h"

bool setBanca(int banca){
  if (banca < 0) {
    return false
  } else {
    banca_ = banca;
    return true;
  }
}
