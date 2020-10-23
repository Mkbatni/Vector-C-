# Vector-C-
Vector liberary with more features than the C++ standard library vector




Vector<double> doubleVec{1.5, 2.5 , 3.5, 4.5};
	Vector<int> iv(intVec);
	Vector<double> dv(doubleVec);
	cout << "intVec" << intVec << endl; 
// "intVec(1, 3, 5, 7, 9)" 
	cout << "iv" << iv << endl; 
// "iv(1, 3, 5, 7, 9)"
	cout << "doubleVec" << doubleVec << endl; 
// "doubleVec(1.5, 2.5, 3.5, 4.5)" 
cout << "dv" << dv << endl; 
// "dv(1.5, 2.5, 3.5, 4.5)" 



cout << "if inVec == intVec2 with same elments : " << (intVec == intVec )<<"  it is false: "
 << (intVec != intVec2)  <<endl;



Vector<int> newVec (intVec);
Vector<double> ddd = doubleVec;
cout << "Assignment operator " << ddd << endl; 
cout << "Copy constructor" << iv << endl; 
iv = intVec	;
cout << "Assignment operator " << iv << endl; 


Vector < int>  intD = 2 * intVec;
cout << "* operator * 2" << intD << endl; 
Vector < int>  indD2 = 3 + intVec;
cout << "+ operator + 3" << indD2 << endl; 


//Calling the friend Functions:


cout << "\n\nFriend Function TEst--> ";
cout << intVec << endl;
addNum(3,intVec);
mulNum(3,intVec);


