#include "gtest/gtest.h"

#include "../GameCharacter.h"

TEST(GameCharacter, DefaultConstructor) {
    GameCharacter c;
    ASSERT_EQ(0, c.getXPos());
    ASSERT_EQ(0, c.getYPos());
    ASSERT_FALSE(c.isFighting());
}


TEST(GameCharacter, TestFightingMove) {
    GameCharacter c;
    c.setFighting(true);
    ASSERT_TRUE(c.isFighting());
    c.move(1, 1);  // moving should disable fighting
    ASSERT_FALSE(c.isFighting());
}
