// Patterns

#include<iostream>
using namespace std;

void pattern1(int size){ // Rectangle of size*size

	for(int i = 0;i<size;i+=1){

		for(int j = 0;j<size;j+=1){

			cout<<"*";

		}
	cout<<endl;

	}

}

void pattern2(int size){ // Pyramid

	for(int i=0;i<size;i+=1){

		for(int j=0;j<=i;j+=1){

			cout<<"*";

		}
	cout<<endl;

	}

}

void pattern3(int size) { // Reverse Pyramid

	for(int i = 0;i<size;i+=1){

		for(int j = size;j>i;j-=1){

		cout<<"*";
	}

	cout<<endl;

	}

}

void pattern4(int size){ // Pyramid with numbers

	for(int i= 1;i<=size;i+=1){

		for(int j=1;j<=i;j+=1){

			cout<<j;

		}
	cout<<endl;

	}
}

void pattern5(int size){ // Pyramid + Reverse Pyramid

    for(int i=1;i<size;i+=1){

        for(int j=0;j<i;j+=1){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = 0; i<size;i+=1){
        for(int j = size;j>i;j-=1){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int size){ // Right Pyramid

    for(int i = 0;i<size;i+=1){

        for(int j = size-1;j>i;j-=1){
            cout<<"-";
        }

        for(int k = 0;k<=i;k+=1){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern7(int size){ // Left Pyramid

    for(int i=0;i<size;i+=1){

        for(int j = 0;j<i;j+=1){
            cout<<"-";
        }

        for(int k = size;k>i;k-=1){
            cout<<"*";
        }
       cout<<endl;
    }
}

void pattern8(int size){ // Equilateral Triangle

    for(int i=0;i<size;i+=1){

        for(int j=size-1;j>i;j-=1){
            cout<<"-";
        }

        for(int k = 0;k<(i*2)+1;k+=1){
            cout<<"*";
        }

        for(int l=size-1;l>i;l-=1){ // This is optional as the traingle is already symmetrical
            cout<<"-";
        }

        cout<<endl;

    }
}

void pattern9(int size){ // Reversed Equilateral Triangle

    for(int i=0;i<size;i+=1){

        for(int j=0;j<i;j+=1){
            cout<<"-";
        }

        for(int k=0;k<2*(size-i)-1;k+=1){
            cout<<"*";
        }

        for(int l=0;l<i;l+=1){ // This is optional as the traingle is already symmetrical
            cout<<"-";
        }

        cout<<endl;
    }

}

void pattern10(int size){ // Equilateral Triangle with spacing in between stars

    for(int i = 0;i<size;i+=1){

        for (int j = size - 1; j>i; j-=1) {
            cout << "-";
        }

        for(int k = 0;k<=i;k+=1){
            cout<<"* ";
        }

        cout<<endl;
    }

}

void pattern11(int size){ // Reversed Equilateral Triangle with spacing in between stars

    for(int i = 0;i<size;i+=1){

        for (int j = 0; j<=i; j+=1) {
            cout << "-";
        }

        for(int k = size;k>i;k-=1){
            cout<<"* ";
        }

        cout<<endl;
    }

}

int main(){

	cout<<"Welcome to Patterns"<<endl;

	pattern11(5);

	return 0;


}

