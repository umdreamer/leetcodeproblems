.PHONY : validNumber \
         wordLadderII \
         coinChange \
         rangeSumQueryImmutable \
         zigzagConversion
  
zigzagConversion: zigzagConversion.cpp
		g++ -o $@ $^

addTwoNumbers: addTwoNumbers.cpp
		g++ -o $@ $^

rotateList: rotateList.cpp
		g++ -o $@ $^
         
uglyNumber: uglyNumber.cpp
		g++ -o $@ $^

validNumber : validNumber.cpp
		g++ -o $@ $^

wordLadderII : wordLadderII.cpp
		g++  -Wc++11-extensions wordLadderII.cpp -o wordLadderII

coinChange: coinChange.cpp
		g++  -Wc++11-extensions coinChange.cpp -o coinChange

rangeSumQueryImmutable: rangeSumQueryImmutable.cpp
		g++  -Wc++11-extensions rangeSumQueryImmutable.cpp -o rangeSumQueryImmutable

rangeSumQuery2DImmutable: rangeSumQuery2DImmutable.cpp
		g++  -Wc++11-extensions rangeSumQuery2DImmutable.cpp -o rangeSumQuery2DImmutable
addDigits: addDigits.cpp
		g++  -Wc++11-extensions addDigits.cpp -o addDigits 
validAnagram : validAnagram.cpp
		g++  -Wc++11-extensions validAnagram.cpp -o validAnagram
containsDuplicate: containsDuplicate.cpp
		g++  -Wc++11-extensions containsDuplicate.cpp -o containsDuplicate
		
excelSheetColumnNumber: excelSheetColumnNumber.cpp
		g++  -Wc++11-extensions excelSheetColumnNumber.cpp -o excelSheetColumnNumber

removeElement: removeElement.cpp
		g++  -Wc++11-extensions removeElement.cpp -o removeElement 

removeLinkedListElement: removeLinkedListElement.cpp
		g++  -Wc++11-extensions removeLinkedListElement.cpp -o removeLinkedListElement 

happyNumber: happyNumber.cpp
		g++  -Wc++11-extensions happyNumber.cpp -o happyNumber 

romanToInteger: romanToInteger.cpp
		g++  -Wc++11-extensions romanToInteger.cpp -o romanToInteger

integerToRoman: integerToRoman.cpp
		g++  -Wc++11-extensions integerToRoman.cpp -o integerToRoman
