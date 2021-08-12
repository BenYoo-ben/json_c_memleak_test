# json_c_memleak_test
experiments on json-c(v0.13) to ensure that no memory leakage is present in the library.  

detailed information can be found in  
https://www.notion.so/json-c-0-13-memory-leak-16b9a6b388ca440c99ff3df9fbc6d174  
  
1. Clone Repository: git clone "https://github.com/BenYoo-ben/json_c_memleak_test.git"  
2. Check for Valgrind version: valgrind --version (only to check if valgrind is installed in the system.)  
3. Build using Makefile: make  
4. Choose program to test: (add .c codes in src/ directory.)  
5. Run mem_check shell scirpt: ./mem_check.sh $EXECUTABLE  
6. View Results : (Summary will be displayed & detailed information is stored in $EXECUTABLE_NAME.txt as an output)
  
  
- Lib not found: run ./fix.sh  
  


