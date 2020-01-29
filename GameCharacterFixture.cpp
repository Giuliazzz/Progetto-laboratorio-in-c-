#include "gtest/gtest.h"

#include "../GameCharacter.h"


class GameCharacterSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.setXPos(10);
        c.setYPos(10);
        c.setFighting(true);
    }

    GameCharacter c;
};


TEST_F(GameCharacterSuite, TestMove) {
    c.move(12, 14);

    ASSERT_EQ(22, c.getXPos());
    ASSERT_EQ(24, c.getYPos());
}

