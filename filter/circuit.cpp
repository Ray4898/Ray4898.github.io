 #include <iostream>
 #include <string>
 using namespace std;
 #include <vector>
 #include <cmath>
 //#include<math.h>
 #include<algorithm> 
 
 
 double Max_value(vector<double> d1, vector<double> d2){
		
		double max1 = 1/d1[0];
		double max2 = 1/d2[0];
		
		for(int i = 0; i<d1.size();i++)
		{
				if(1/d1[i] >max1)
					max1 = 1/d1[i];
		}
		
		for(int i = 0; i<d2.size();i++)
		{
				if(1/d2[i] >max2)
					max2 = 1/d2[i];
		}
		return max(max1,max2);
	 
	 
	 
	 }
vector<double> increaser(double m, vector<double> d){
	
	vector<double> sim;
	
	for (int i = 0; i< d.size();i++){
		
		sim.push_back(m * d[i]);
	}
	return sim;
}
  
 class S{
         private:
                  int power;
  
         public:
 
                void set_s(int p){
                this->power=p;
                 }
                int get_s(){return power;}
  };
 
 
 class Impedance{
 
         protected:
          float value;
 			string name;

          S s;
 
          int type_;
          int power;
 
         public:
          
 
          virtual void Display() = 0;
          //get info();
		  virtual string get_info() =0;
          
          void set_name(string n){this->name = n;}
		
		  string get_name(){return this->name;}
		  
		  
 
          int get_type(){return type_;}
 
          void set_value(float v){this->value = v;}
          
          float get_value(){return this->value;}
          
          int get_spower(){return this->s.get_s();}
 
          void set_spower(int i){this->s.set_s(i);}
          
          int get_power(){return this->power;}
          
          void set_power(int i){this->power = i;}
 
  };
 
 class Resistor:public Impedance{
 
          
 					
                  
 
          public:
 
          Resistor(){power=1; type_ = 0;s.set_s(0); };
 
          Resistor(float v){
			  
					
					power=1;
					
                  value = v;
 
                  s.set_s(0);
 
                  type_ = 0;
          }
			
			
 
          void Display(){
			  
			  cout << "\033[1;32m" << "Resistor: " << this->name << " ,value :" << this->value << " ohm" << "\033[0m" << endl ;
			  
			  
			  
		}
		string get_info(){
			  string info="";
			  info += "Resistor: ";
			  info += this->name;
			  info +=" ,value :";
			  info += to_string(this->value);
			  info += " ohm";
			  return info;
			
		} 
		 
 
 
 
  };
 
 class Capacitor:public Impedance{
 
          
				
 
          public:
 
         Capacitor(){ power=-1; type_ = 1;s.set_s(-1); };
 
          Capacitor(float v){
			  
			  
			  power=-1;
			  
				value = v;
 
                s.set_s(0);
 
                type_ = 0;
                
                power=-1;
 
  }
		
 
          
 
          void Display(){cout << "\033[1;33m" << "capacitor: " << this->name << " ,value :" << this->value << " F"
			  
			  << "\033[0m" << endl;}
		  
		  string get_info(){
			  string info="";
			  info += "Capacitor: ";
			  info += this->name;
			  info +=" ,value :";
			  info += to_string(this->value);
			  info += " F";
			  return info;
			
		} 
          
 
          
			
		 
  };
 
 class Inductor:public Impedance{
 
          
 
          public:
          
         Inductor(){ power=1; type_ = 2; s.set_s(1); };
 
		 Inductor(float v){
			 
				power =1;
				
				value = v;
 
                s.set_s(1);
 
                type_ = 2;
			}
			
          void set_power(int p){this->power = p;}
          
          int get_power(){return this->power;}
 
          void Display(){cout << "\033[1;34m" << "inductor: " << this->name << " ,value :" << this->value << " H"
			  
			 << "\033[0m" << endl;}
		  
		  string get_info(){
			  string info="";
			  info += "Inductor: ";
			  info += this->name;
			  info +=" ,value :";
			  info += to_string(this->value);
			  info += " H";
			  return info;
			
		} 
          
  };
 class Trans{

         private:

                 vector<Impedance*> tf_top;
                 vector<Impedance*> tf_low;
                 
                 
                 

         public:



				 void set_tf_top(vector<Impedance*> top){ 
					 
						
						this->tf_top = top;
						
					 }
				 
				 void set_tf_low(vector<Impedance*> low){
					 
						
						this->tf_low = low;}

				 vector<Impedance*> get_tf_top(){return tf_top;}
				 
				 vector<Impedance*> get_tf_low(){return tf_low;}
				 
				 

				 

				 
				//simplify the function
				 void simplify(){
					 
					 vector<double> top_cof;
					 vector<double> low_cof;
					 int max;
					 
					 // s simplification
					 for (int i = 0; i < this->tf_top.size(); i++)
					 {
						 top_cof.push_back(pow(2,this->tf_top[i]->get_spower()));
						 
					 }
					 
					 for (int i = 0; i < this->tf_low.size(); i++)
					 {
						 low_cof.push_back(pow(2,this->tf_low[i]->get_spower()));
					 }
					 
					 double multiplier = Max_value(top_cof, low_cof);
					 
					 top_cof = increaser(multiplier,top_cof);
					 
					 low_cof = increaser(multiplier,low_cof);
					 
					 for (int i = 0; i< this->tf_top.size(); i++)
						
					{
							this->tf_top[i]->set_spower(int(log2(top_cof[i])));
					}
					
					for (int i = 0; i< this->tf_low.size(); i++)
						
					{
							this->tf_low[i]->set_spower(int(log2(low_cof[i])));
					}
					
					
					 
					 
					 }
				 
				//display the function
				 void displaytf(){
					 float top_num=0;
					 float low_num=0;
					 string top_out;
					 string low_out;
					 
						 
						 
						 vector<vector<Impedance*> > V_top_cof;
						 vector<vector<Impedance*> > V_low_cof;
						 int Max_top=0;
						 int Max_low = 0;
						 //top-max-spower
						 for (int i=0; i< this->tf_top.size(); i++ )
						 {
								if(this->tf_top[i]->get_spower() > Max_top )
									Max_top = this->tf_top[i]->get_spower();
						 }
						 
								
						 for (int i=0; i< this->tf_low.size(); i++ )
						 {
								
								if(tf_low[i]->get_spower() > Max_low )
									Max_low = this->tf_low[i]->get_spower();
						 }
						 
						 
						 //top_spower_group
					for (int j = 0; j <= Max_top; j++)
						 {
							 vector<Impedance*> temp;
							 for( int i =0; i <this->tf_top.size(); i++)
							 {
									if(this->tf_top[i]->get_spower() == j ){
										temp.push_back(this->tf_top[i]); }
							 }
							 
								V_top_cof.push_back(temp);
							 
							 
						}
						
						//low_spower
						for (int j = 0; j <= Max_low; j++)
						 {
							 vector<Impedance*> temp;
							 for( int i =0; i < this->tf_low.size(); i++)
							 {
									
									if(this->tf_low[i]->get_spower() == j ){
										temp.push_back(this->tf_low[i]);
											
									}
							 }
						 
							V_low_cof.push_back(temp);	 
						}
						
						//display top
						float temp=0;
						cout << " ";
						  
						for (int j = Max_top; j >=0; j-- )
						{
								for (int i =0; i<V_top_cof[j].size(); i++)
									{
											temp = pow(V_top_cof[j][i]->get_value(),V_top_cof[j][i]->get_power()) + temp;
									}
								if( j ==0 )
									{	
											if(temp != 0){
												cout << "+ " << temp << endl;
												
											}
											else{
												cout << endl;
												
											}
									}
								else if(j ==1 && temp != 0){
										
												cout << " + " << temp << "S " ;
												
										//cout << temp << "S " ;
									}
								else if (temp!=0){
									
									cout << temp << "S^" << j  ;
									
								}
										
								temp =0;
							
						}
						
								for (int i =0; i< tf_low.size(); i++){
								 
								 cout << "-----";
								 
							 }
							 cout << endl;
										
							 
							 //display low
							 temp =0;
							 for (int j = Max_low; j >=0; j-- )
								{
										for (int i =0; i<V_low_cof[j].size(); i++)
											{
													temp = pow(V_low_cof[j][i]->get_value(),V_low_cof[j][i]->get_power()) + temp;
														
											}
										if( j ==0 && temp != 0)
											{
													cout << temp << endl;
													
											}
										else if(j ==1 && temp != 0){
												cout << temp << "S + " ;
												
											}
										else if (temp!=0){
											
											cout << temp << "S^" << j << " + " ;
											
										}
												
										temp =0;
									
								}
					
							
					 
					 }
			//get string 
			string get_function_string(){
					 string function = "";
					 float top_num=0;
					 float low_num=0;
					 string top_out;
					 string low_out;
					 
						 
						 
						 vector<vector<Impedance*> > V_top_cof;
						 vector<vector<Impedance*> > V_low_cof;
						 int Max_top=0;
						 int Max_low = 0;
						 //top-max-spower
						 for (int i=0; i< this->tf_top.size(); i++ )
						 {
								if(this->tf_top[i]->get_spower() > Max_top )
									Max_top = this->tf_top[i]->get_spower();
						 }
						 
								
						 for (int i=0; i< this->tf_low.size(); i++ )
						 {
								
								if(tf_low[i]->get_spower() > Max_low )
									Max_low = this->tf_low[i]->get_spower();
						 }
						 
						 
						 //top_spower_group
					for (int j = 0; j <= Max_top; j++)
						 {
							 vector<Impedance*> temp;
							 for( int i =0; i <this->tf_top.size(); i++)
							 {
									if(this->tf_top[i]->get_spower() == j ){
										temp.push_back(this->tf_top[i]); }
							 }
							 
								V_top_cof.push_back(temp);
							 
							 
						}
						
						//low_spower
						for (int j = 0; j <= Max_low; j++)
						 {
							 vector<Impedance*> temp;
							 for( int i =0; i < this->tf_low.size(); i++)
							 {
									
									if(this->tf_low[i]->get_spower() == j ){
										temp.push_back(this->tf_low[i]);
											
									}
							 }
						 
							V_low_cof.push_back(temp);	 
						}
						
						//display top
						float temp=0;
						
						function += " ";
						for (int j = Max_top; j >=0; j-- )
						{
								for (int i =0; i<V_top_cof[j].size(); i++)
									{
											temp = pow(V_top_cof[j][i]->get_value(),V_top_cof[j][i]->get_power()) + temp;
									}
								if( j ==0 )
									{	
											if(temp != 0){
												
												function += "+ ";
												function += to_string(temp);
												function += "\n";
											}
											else{
												
												function += "\n";
											}
									}
								else if(j ==1 && temp != 0){
										
												
												function += "+ ";
												function += to_string(temp);
												function += "S ";
										//cout << temp << "S " ;
									}
								else if (temp!=0){
									
									
									function += to_string(temp);
									function += "S^";
									function += to_string(j);
								}
										
								temp =0;
							
						}
						
								for (int i =0; i< tf_low.size(); i++){
								 
								 
								 function += "------";
							 }
							 cout << endl;
							function += "\n";		
							 
							 //display low
							 temp =0;
							 for (int j = Max_low; j >=0; j-- )
								{
										for (int i =0; i<V_low_cof[j].size(); i++)
											{
													temp = pow(V_low_cof[j][i]->get_value(),V_low_cof[j][i]->get_power()) + temp;
														
											}
										if( j ==0 && temp != 0)
											{
													
													function += to_string(temp);
													function += "\n";
											}
										else if(j ==1 && temp != 0){
												
												function += to_string(temp);
												function += "S + " ;
											}
										else if (temp!=0){
											
											
											function += to_string(temp);
											function += "S^";
											function += to_string(j);
											function += " + ";
										}
												
										temp =0;
									
								}
								return function;
					 }
	};

 class Circuit{
 
         private:
					vector<Impedance*> Cir;
	 
					vector<Impedance*> vout;
	 
					Trans t;
					
					string name;
        public:

					 Circuit():t(){};

					 Circuit(vector<Impedance*> v){

					  for(int i = 0; i < v.size(); i++)
					  {
							 Cir.push_back(v[i]);


					 }

			 }
			 //get_circuit
				string get_circuit_info(){
					string circuit ="";
					for (int i = 0; i < this->Cir.size(); i++)
						 {
							circuit += this->Cir[i]->get_info();
							circuit += "\n" ;
						 }
						 return circuit;
					
				}
				string get_vout_info(){
					string out ="";
						   for (int i = 0; i <vout.size();i++)
						 {
							out += vout[i]->get_info();
							out += "\n" ;
						 }
					return out;
					
				}
				void display_circuit(){
						 for (int i = 0; i < Cir.size(); i++)
						 {
							Cir[i]->Display();
						 }
					 }
				void display_vout(){
						 cout << "Vout: " << endl;
						 for (int i = 0; i <vout.size();i++)
						 {
							vout[i]->Display();
						 }
						 
						 }

				void set_tf(vector<Impedance*> top, vector<Impedance*> low){
							 this->t.set_tf_top(top);
							 this->t.set_tf_low(low);
					 }

					 Trans get_tf(){return this->t;}

					 void add_element(Impedance* i){this->Cir.push_back(i);}

					 void add_vout(Impedance* i){this->vout.push_back(i);}

					 vector<Impedance*> get_circuit(){return this->Cir;}
					 
					 vector<Impedance*> get_vout(){return this->vout;}
					 
					 void set_name(string n){this->name = n;}
					 
					 string get_name(){return this->name;}

					 void clean_v(){this->Cir.clear();}

 };

 
