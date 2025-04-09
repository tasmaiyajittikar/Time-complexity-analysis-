The "insertionSort.cpp" file contains the program code for Insertion Sort algorithm. We need to use appropriate program file names for each algorithm. 

How to run the code? 

Steps:
1. Open and login to your Putty and WinSCP software. 

2. Copy the program file to the server and make sure to keep the file in a folder and inside the same folder there should be another folder named "inputs" and all the input files should be there. 

3. Now on your Putty software access that folder and now you are ready to compile and run the code. 

4. To compile the code run the following command - 
	g++ Insertion/insertionSort.cpp
   - Here, insertionSort.cpp is the program file and we need to change the program file name for other algorithms.
   - For  the Heap Sort we need to compile the program as g++ HeapSort/demo.cpp HeapSort/minheap.cpp

5. To run the code run the following instructions (this will test one sample file): 
	./a.out inputs/input.10.1 
   - Here "input.10.1" is the input file and we need to change it for each one of them in the folder to get the runtime. 

6. To run and get the runtime run the following command - 
	time for f in inputs/input.10.1; do echo $f; ./a.out $f; done

Now, you should be able to see the program output based on your input file. 