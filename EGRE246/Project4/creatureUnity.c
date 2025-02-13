//  gcc unity.c creatureUnity.c creature.c
#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "world.h"
#include "geometry.h"
#include "creature.h"

#define MAKE_CREATURE newCreature(1,createSpecies("mongrol"),newWorld("Krypton",20,20),createPoint(5,10),NORTH)

void setUp(void){  /* set stuff up here */ }
void tearDown(void){ /* clean stuff up here */ }

void newCreature_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_NOT_NULL_MESSAGE(c,"newCreature #1 failed");
}

void freeCreature_(void) {
  creature c = MAKE_CREATURE;
  freeCreature(c);
}

void getId_(void) {
  creature c = MAKE_CREATURE;
  int id = getId(c);
  TEST_ASSERT_EQUAL_INT_MESSAGE(1,id,"getId #1 failed");
}

void setId_(void) {
  creature c = MAKE_CREATURE;
  setId(c,99);
  int id = getId(c);
  TEST_ASSERT_EQUAL_INT_MESSAGE(99,id,"setId #1 failed");
}

void getWorld_(void) {
  creature c = MAKE_CREATURE;
  char *name = getName(getWorld(c));
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Krypton",name,"getWorld #1 failed");
}

void setWorld_(void) {
  creature c = MAKE_CREATURE;
  setWorld(c, newWorld("Vulcan",15,20));
  char *name = getName(getWorld(c));
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Vulcan",name,"setWorld #1 failed");  
}

void getPoint_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_EQUAL_INT_MESSAGE(5,getRow(getPoint(c)),"getPoint #1 failed");
  TEST_ASSERT_EQUAL_INT_MESSAGE(10,getCol(getPoint(c)),"getPoint #2 failed");
}
void setPoint_(void) {
  creature c = MAKE_CREATURE;
  setPoint(c,createPoint(20,30));
  TEST_ASSERT_EQUAL_INT_MESSAGE(20,getRow(getPoint(c)),"setPoint #1 failed");
  TEST_ASSERT_EQUAL_INT_MESSAGE(30,getCol(getPoint(c)),"setPoint #2 failed");
}

void getDirection_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_EQUAL_INT_MESSAGE(NORTH,getDirection(c),"getDirection #1 failed");
}

void setDirection_(void) {
  creature c = MAKE_CREATURE;
  setDirection(c,WEST);
  TEST_ASSERT_EQUAL_INT_MESSAGE(WEST,getDirection(c),"setDirection #1 failed");
}

void getSpecies_(void) {
  creature c = MAKE_CREATURE;
  species s = getSpecies(c);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("",getSpeciesName(s),"getSpecies #1 failed");
}

void setSpecies_(void) {
  creature c = MAKE_CREATURE;
  setSpecies(c,createSpecies("test"));
  char *name = getSpeciesName(getSpecies(c));
  TEST_ASSERT_EQUAL_STRING_MESSAGE("",name,"setSpecies #1 failed");  
}

void getPC_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_EQUAL_INT_MESSAGE(1,getPC(c),"getPC #1 failed");
}

void isRunning_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_EQUAL_INT_MESSAGE(false,isRunning(c),"isRunning #1 failed");
}
void takeTurn_(void) {
  // creature c = MAKE_CREATURE;
  //takeTurn(c);
}

void toCreatureString_(void) {
  creature c = MAKE_CREATURE;
  TEST_ASSERT_EQUAL_STRING_MESSAGE("(\"\",#1,(row:5,col:10),north)",toCreatureString(c),"toCreatureString #1 failed");
}

int main ( void ){
  UNITY_BEGIN();
  RUN_TEST(newCreature_);
  RUN_TEST(freeCreature_);
  RUN_TEST(getId_);
  RUN_TEST(setId_);
  RUN_TEST(getWorld_);
  RUN_TEST(setWorld_);
  RUN_TEST(getPoint_);
  RUN_TEST(setPoint_);
  RUN_TEST(getDirection_);
  RUN_TEST(setDirection_);
  RUN_TEST(getSpecies_);
  RUN_TEST(setSpecies_);
  RUN_TEST(getPC_);
  RUN_TEST(isRunning_);
  RUN_TEST(takeTurn_);
  RUN_TEST(toCreatureString_);
  return UNITY_END();
}
   
