/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
static const Piece INVALID = -1;
static const Piece EMPTY = 0;
static const Piece WHITE = 1;
static const Piece BLACK = 2;

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//change grid values
TEST(ConnectXTEST, Gridchange1)
{
   ConnectX grid(1,-1,1);
//   grid.showBoard();
}

TEST(ConnectXTEST, Gridchange)
{
   ConnectX grid(-1,-1,-1);
//   grid.showBoard();
}

TEST(ConnectXTEST, Gridchange2)
{
   ConnectX grid(1,1,-1);
//   grid.showBoard();
}

//Place first black
TEST(ConnectXTest, placeBlackFirstTime)
{
   ConnectX con;
   con.placePiece(0);
   ASSERT_EQ(BLACK,con.at(0,5));
   
}

//Second value after black should be white
TEST(ConnectXTest, placeWhiteAfterBlack)
{
   ConnectX con;
   int i; 
   con.placePiece(4);
   i=con.whoseTurn();
   ASSERT_EQ(WHITE,i); 
   con.placePiece(2);
   
}

//Test for toggle
TEST(ConnectXTest, placeAlternate)
{
   ConnectX con;
   int i; 
   con.placePiece(4);
   i=con.whoseTurn();
   ASSERT_EQ(WHITE,i); 
   con.placePiece(2);
   i=con.whoseTurn();
   ASSERT_EQ(BLACK,i); 
   con.placePiece(3);
   //con.showBoard();
}

//out of bounds condition for width
TEST(ConnectXTest,AccessOutsideGridWidth)
{
   ConnectX con;
   //con.placePiece(-1);
   ASSERT_EQ(INVALID,con.at(-1,3));
}


//positive out of bounds condition for width
TEST(ConnectXTest,AccessGreaterOutsideGridWidth)
{
   ConnectX con;
   con.placePiece(100);
   ASSERT_EQ(INVALID,con.at(100,5));
}

//out of bounds condition for height
TEST(ConnectXTest,AccessOutsideGridHeight)
{
   ConnectX con;
   con.placePiece(4);
   ASSERT_EQ(INVALID,con.at(1,-3));
}

//positive out of bounds condition for heigth
TEST(ConnectXTest,AccessGreaterOutsideGridHeight)
{
   ConnectX con;
   con.placePiece(5);
   ASSERT_EQ(INVALID,con.at(1,100));
}


//invalid move should toggle
TEST(ConnectXTest,placeOutsideGridWidth)
{
   ConnectX con;
   int i;
   con.placePiece(-3);
   i=con.whoseTurn();
   ASSERT_EQ(WHITE,i);
  // con.showBoard();
}


//one above other
TEST(ConnectXTest, inLine)
{
   ConnectX con(3,3,3);
   int i; 
   con.placePiece(2);
   con.placePiece(2);
   con.placePiece(2);
   con.placePiece(2);
   i=con.whoseTurn();
   ASSERT_EQ(BLACK,i);
   con.showBoard(); 
}
//all cells are filled
TEST(ConnectXTest, FillAll)
{
   ConnectX con(2,2,2);
   int i; 
   con.placePiece(0);
   con.placePiece(0);
   con.placePiece(1);
   con.placePiece(1);
   con.placePiece(0);
   con.placePiece(1);
   i=con.whoseTurn();
   ASSERT_EQ(BLACK,i);
   con.showBoard();
}
//should return correct value at the position
TEST(ConnectXTest,CorrectValueReturned)
{
   ConnectX con;   
   con.placePiece(2);
   ASSERT_EQ(BLACK,con.at(2,5));
  // con.showBoard();


}


TEST(ConnectXTest,placeWidthNotValid)
{
   ConnectX con;
   con.placePiece(-5);
   ASSERT_EQ(INVALID,con.at(-5,5));
   
}









