#include <iostream>
#include <vector>
#include "circuit.cpp"
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;
void display_main_menu(){
	
	cout << "please select an options: (1/2/3)"<< endl;
	cout << "load a circuit filter  (1)" << endl;
	cout << "build circuit filter   (2)" << endl;  
	cout << "quick                  (3)" << endl;
	
	
}
void display_menu(){
	
	cout << "please select which element you want to add: (0/1/2)"<< endl;
	cout << "Resistor  (0)" << endl;
	cout << "Capacitor (1)" << endl;  
	cout << "inductor  (2)" << endl;
	
	
}

vector<Impedance*> remove_element(vector<Impedance*> v, int inde)
{
	vector<Impedance*> temp;
	temp = v;
	temp.erase(temp.begin()+inde);
	return temp;
	
	
}

//split function
vector<string> split(string s, char c){
	
	vector<string> split_v;
	string temp ="";
	for (int i =0; i <s.size(); i++){
		if(s[i] != c && s[i] != ' '){
			temp = temp +s[i];
			
		}
		else if (s[i] == c)
			{	
				
				split_v.push_back(temp);
				temp = "";
				
			}
		
		
	}
	split_v.push_back(temp);
	
	return split_v;
}
//filter function
string filter_out(string s, char c){
	string temp ="";
	for (int i =0; i<s.size();i++)
	{
		if(s[i]!=c)
			temp = temp +s[i];
		else 
			{
				return temp;
				break;
				
			}
		
		
	}
	return temp;
	
}

int main(){

		int t = 1;
		string ans = "";
		int ans2 ;
		string name;
		float value;
		vector<Circuit> filter;
		display_main_menu();
		cin >> ans;
		//-------------------------------load circuit-----------------------------------
		if(ans == "1"){
			string line;
			cout << "please enter the file name: " ;
			cin >> ans;
			ifstream input;
			input.open(ans);
			cout << "opening" << endl;
			string type;
			string name;
			Circuit cir;
			float value;
			int output=0;
			int end_cir = 1;
			int made_cir =0;
			while (getline(input,line)){
				if(line == "---------------------------------------------------------------" ){
					end_cir =1;
					made_cir = 0;
					cir.set_tf(cir.get_vout(), cir.get_circuit());
					filter.push_back(cir);
				}
		else{
			
		 if(made_cir ==1){
			 
				if(line == "output:"){
						output = 1;
							cout << "output" << endl;
					}
				else{
					vector<string> compoment = split(line,',');
						
					vector<string> imped_name = split(compoment[0],':');
					vector<string> imped_value = split(compoment[1],':');
					if(imped_name[0] == "Resistor" || imped_name[0] == "resistor"){
						if(output ==0){
							Resistor* R = new Resistor;
							R->set_name(imped_name[1]);
								
							R->set_value(stof(filter_out(imped_value[1],'o')));
								
							cir.add_element(R);
						}
						else{
							Resistor* R = new Resistor;
							R->set_name(imped_name[1]);
								
							R->set_value(stof(filter_out(imped_value[1],'o')));
								
							cir.add_vout(R);
							 
					}
				}
					else if(imped_name[0] == "Capacitor" || imped_name[0] == "capacitor"){
						if(output ==0){
							Capacitor* ca = new Capacitor;
							ca->set_name(imped_name[1]);
							ca->set_value(stof(filter_out(imped_value[1],'F')));
							cir.add_element(ca);
					}
						else{
							Capacitor* ca = new Capacitor;
							ca->set_name(imped_name[1]);
							ca->set_value(stof(filter_out(imped_value[1],'F')));
							cir.add_vout(ca);
						}
					}
					else if(imped_name[0] == "Inductor" || imped_name[0] == "inductor"){
						 if(output ==0){
							 Inductor* ind = new Inductor;
							 ind->set_name(imped_name[1]);
							 ind->set_value(stof(filter_out(imped_value[1],'H')));
							 cir.add_element(ind);
						 }
						 else {
							 Inductor* ind = new Inductor;
							 ind->set_name(imped_name[1]);
							 ind->set_value(stof(filter_out(imped_value[1],'H')));
							 cir.add_vout(ind);
						 }
						
					}
					
					
				}
		}	
			else if(end_cir ==1 && made_cir == 0){
					vector<string> new_cir = split(line,':');
				//if(columns[0] == "circuit"){
						/*if(output = 1)
							filter.push_back(cir);*/
						
							new(&cir) Circuit;
							cir.set_name(new_cir[1]);
										cout << new_cir[1] << endl;
							output = 0;
							end_cir = 0;
							//made circuit become true
							made_cir =1;
							//getline(input,line);
					
				}
			
			}

	}	
		cir.set_tf(cir.get_vout(), cir.get_circuit());	
		filter.push_back(cir);	
		input.close();
		}
		
		
	//--------------------build circuit ---------------------------------------------------
		
		else if (ans == "2"){
		
		//main while loop for building circuit filter
		while (t != 0){
			
			cout << "Do you want to add a circuit? 0(no), 1(yes)" << endl;
			
			
			cin >> ans;
			if (ans  != "1" && ans != "y"){
				t =0;
				
			}
			else
			{
				
					int t2 = 1;
					Circuit cir;
					cout << "enter the name of this circuit: " << endl;
					cin >> name;
					cir.set_name(name);
					// while loop for the circuit elements
					while (t2 != 0){
						display_menu();
						
						cin >> ans2;
						
						switch(ans2){
							
							case 0:
							{
								Resistor* R = new Resistor;
								cout << "enter the name of this element : " << endl;
								cin >> name;
								R->set_name(name);
								cout << "enter the vlaue of this element in ohm: "<< endl;
								cin >> value;
								R->set_value(value);
								cir.add_element(R);
							}
							break;
							case 1:
							{
								Capacitor* ca = new Capacitor;
								cout << "enter the name of this element: " << endl;
								cin >> name;
								ca->set_name(name);
								cout << "enter the vlaue of this element in F: "<< endl;
								cin >> value;
								ca->set_value(value);
								cir.add_element(ca);
							}
							break;
							case 2:
							{
								Inductor* ind = new Inductor;
								cout << "enter the name of this element: " << endl;
								cin >> name;
								ind->set_name(name);
								cout << "enter the vlaue of this element in H: "<< endl;
								cin >> value;
								ind->set_value(value);
								cir.add_element(ind);
							}
							break;
							default:
								cout << "please enter 0(resistor), 1(capacitor) or 2(inductor) " << endl;
								break;
						}
						cout << "\033[1;31m" << "circuit: " ;
						cout  << cir.get_name() << ": " << "\033[0m" << endl;
						//cout << cir.get_name() << " : " << endl;
						cir.display_circuit();
						cout << "do you want to add more element ?yes(1)/No(0)" << endl;
						cin >> ans;
						if (ans != "1" && ans != "y")
							t2=0;
						
							
				}
				//vout
							
							int i;
							int t3 = 1;
							int select;
							vector<Impedance*> temp;
							
							temp = cir.get_circuit();
							//while loop to add more vout
							while(t3 !=0){
								cout << "please point out which element(s) you would use as output voltage: " << endl;
								
								for (i=0; i< temp.size(); i++){
									
									cout << "(" << i << ")" << " ";
									temp[i]->Display();
								}
								
								cin >> select;
								cir.add_vout(temp[select]);
								cout << "\033[1;31m" << "circuit: " ;
								cout << cir.get_name() << ": " << "\033[0m" << endl;
								cout << "output: ";
								cir.display_vout();
								temp = remove_element(temp, select);
								cout << "would you like to add more output? yes(1)/no(0)" << endl;
								cin >> ans;
								if(ans != "1" && ans != "y")
									t3=0;
									
								cir.set_tf(cir.get_vout(), cir.get_circuit());
						
					
				
				
			}
			
			//cir.display_circuit();
			filter.push_back(cir);
			
			
			
		}
	}
	}
	else{
		cout << "have a good day" << endl;
		exit(0);
	}
	cout << "---------------------------------------------------------------" <<endl;
	for (int i = 0; i<filter.size();i++)
		{
				cout << "\033[1;31m" << "circuit: "  << i+1 << " " ;
				cout << filter[i].get_name() << ": " << "\033[0m" <<endl;
				filter[i].display_circuit();
				cout << "output:" << endl;
				filter[i].display_vout();
				cout << "transfer function: " << endl;
				
				filter[i].get_tf().simplify();
				filter[i].get_tf().displaytf();
				
				cout << "---------------------------------------------------------------" <<endl;		
				
		}
		cout << "do you want to save the circuit to a file? 0(no) 1(yes)?" << endl;
		cin >> ans;
		if(ans != "1" && ans != "y")
			cout << "bye, " << endl;
		else
			{
					ofstream myfile;
					cout << "enter the name of the file: " ;
					cin >> ans;
					myfile.open(ans);
					//ofstream cout(ans);
					myfile << "---------------------------------------------------------------" <<endl;
					for (int i = 0; i<filter.size();i++)
						{
								myfile  << "circuit: "  << i+1 << " " ;
								myfile << filter[i].get_name() << ": "  <<endl;
								myfile << filter[i].get_circuit_info();
								myfile << "output:" << endl;
								myfile << filter[i].get_vout_info();
								myfile << "transfer function: " << endl;
								
								//filter[i].get_tf().simplify();
								myfile << filter[i].get_tf().get_function_string();
								
								myfile << "---------------------------------------------------------------" <<endl;		
				
		}
					myfile.close();
				
				
			}
		
	
	



return 0;
}

