Kshitija Karkar

Bugs found :

1. The inBounds() is not coded correctly.
      -For negative or out of bound values of w, final outcome should be invalid even for correct h values. 
      -Separate if() conditions change the value of inside variable.
      -Hence only h values are checked and w values get ignored. 
      
2. at()
      -out of bounds value for width returns garbage value instead of INVALID
      -at(100,3) should return INVALID instead returns a garbage value.

3. toWin number should be restricted to values between height and width.
      -If parameterized constructor has values (3,3,4), width=3,height=3 and toWin=4
      -In no scenario the above toWin condition will be satisfied as the maximum value for black or
       white to win should be 3 in row or column or diagonally. 

       
4. placePiece() - It should check whether entire grid is full. Because if there is no cell empty 
                  then game will go in infinite loop.
