#include<iostream>
class rectangle
{
	private:
		int length;
		int breadth;
		public:
		void getdata()
		{
			std::cout<<"enter the length ";
			std::cin>>length;
			std::cout<<"enter the breadth ";
			std::cin>>breadth;
		}
		void display(){
			std::cout<<"length "<<length<<'\n';
			std::cout<<"breadth "<<breadth;
		}		
};
int main()
{
	rectangle r;
	r.getdata();
	r.display();
	return 0;
}

