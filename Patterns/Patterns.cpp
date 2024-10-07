// Patterns

/*

1.  *****
    *****
    *****
    *****
    *****


2.  *
    **
    ***
    ****
    *****


3.  *****
    ****
    ***
    **
    *


4.  1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5


5.  *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *


6.       *
        **
       ***
      ****
     *****


7.   *****
      ****
       ***
        **
         *


8.      *
       ***
      *****
     *******
    *********


9.  *********
     *******
      *****
       ***
        *


10.      *
        * *
       * * *
      * * * *
     * * * * *


11.  * * * * *
      * * * *
       * * *
        * *
         *


12.  * * * * *
      * * * *
       * * *
        * *
         *
         *
        * *
       * * *
      * * * *
     * * * * *


13.      *
        * *
       *   *
      *     *
     *********


14.  *********
      *     *
       *   *
        * *
         *


15.      *
        * *
       *   *
      *     *
     *       *
      *     *
       *   *
        * *
         *


16.           1
            1   1
          1   2   1
        1   3   3   1
      1   4   6   4   1


17.      1
        212
       32123
      4321234
       32123
        212
         1


18.   **********
      ****  ****
      ***    ***
      **      **
      *        *
      *        *
      **      **
      ***    ***
      ****  ****
      **********


19.    *        *
       **      **
       ***    ***
       ****  ****
       **********
       ****  ****
       ***    ***
       **      **
       *        *


20.    ****
       *  *
       *  *
       *  *
       ****

21.    1
       2  3
       4  5  6
       7  8  9  10
       11 12 13 14 15

22.    1
       0 1
       1 0 1
       0 1 0 1
       1 0 1 0 1

23.        *      *
         *   *  *   *
       *      *      *

24.    *        *
       **      **
       * *    * *
       *  *  *  *
       *   **   *
       *   **   *
       *  *  *  *
       * *    * *
       **      **
       *        *

25.       *****
         *   *
        *   *
       *   *
      *****

26.   1 1 1 1 1 1
      2 2 2 2 2
      3 3 3 3
      4 4 4
      5 5
      6

27.   1 2 3 4  17 18 19 20
        5 6 7  14 15 16
          8 9  12 13
            10 11

28.      *
        * *
       * * *
      * * * *
     * * * * *
      * * * *
       * * *
        * *
         *

29.
       *        *
       **      **
       ***    ***
       ****  ****
       **********
       ****  ****
       ***    ***
       **      **
       *        *

30.         1
          2 1 2
        3 2 1 2 3
      4 3 2 1 2 3 4
    5 4 3 2 1 2 3 4 5


31.      4 4 4 4 4 4 4
         4 3 3 3 3 3 4
         4 3 2 2 2 3 4
         4 3 2 1 2 3 4
         4 3 2 2 2 3 4
         4 3 3 3 3 3 4
         4 4 4 4 4 4 4

32.    E
       D E
       C D E
       B C D E
       A B C D E

33.    a
       B c
       D e F
       g H i J
       k L m N o

34.    E D C B A
       D C B A
       C B A
       B A
       A

35.    1      1
       12    21
       123  321
       12344321
*/


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

void pattern12(int size){ // Reversed Equilateral Triangle with spacing in between stars + Equilateral Triangle with spacing in between stars

    pattern11(size);

    pattern10(size);

}

void pattern13(int size){

    for(int i=0;i<size;i+=1){

        for(int j=i;j<size-1;j+=1){
            cout<<" ";
        }

        for(int k=0; k<2*i+1; k+=1){
                    if(k == 0 || k == 2*i || i == size-1){
                        cout << "*";
                    } else {
                        cout << " ";
                    }
                }
        cout<<endl;
    }
}

void pattern14(int size){

    for(int i=0;i<size;i+=1){

        for(int j=i;j<size-1;j+=1){
            cout<<" ";
        }

        for(int k=0; k<2*i+1; k+=1){
                    if(k == 0 || k == 2*i || i == size-1){
                        cout << " ";
                    } else {
                        cout << "*";
                    }
                }
        cout<<endl;
    }
}

void pattern17(int size){
    for(int i=1;i<=size;i+=1){

        for(int space=0;space<size-i;space+=1){
            cout<<" ";
        }

        for(int j=i;j>=1;j-=1){
            cout<<j;
        }

        for(int k=2;k<=i;k+=1){
            cout<<k;
        }

        cout<<endl;
    }

    for(int lower=size-1;lower>0;lower-=1){

        for(int space=0;space<size-lower;space+=1){
            cout<<" ";
        }

        for(int l=lower;l>=1;l-=1){
            cout<<l;
        }

        for(int m=2;m<=lower;m+=1){
            cout<<m;
        }

    cout<<endl;
    }
}

void pattern18(int size){

    // Upper Half

    for(int i=0;i<size;i+=1){

        for(int j=size;j>i;j-=1){
            cout<<"*";
        }

        for(int k=0;k<(2*i);k+=1){
            cout<<" ";
        }

        for(int l=size;l>i;l-=1){
            cout<<"*";
        }
        cout<<endl;
    }

    // Lower Half

    for(int i=0;i<size;i+=1){

        for(int j=0;j<=i;j+=1){
            cout<<"*";
        }

        for(int k=1;k<(2*size)-(2*i)-1;k+=1){
            cout<<" ";
        }

        for(int l=0;l<=i;l+=1){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern19(int size){

    for(int i=1;i<=size;i+=1){

        for(int j=1;j<=i;j+=1){
            cout<<"*";
        }

        for(int k=0;k<(2*size)-(2*i);k+=1){
            cout<<" ";
        }

        for(int l=i;l>0;l-=1){
            cout<<"*";
        }

        cout<<endl;
    }

    for (int i = size - 1; i >= 1; i -= 1) {
        for (int j = 1; j <= i; j += 1) {
            cout << "*";
        }

        for (int k = 0; k < (2 * size) - (2 * i); k += 1) {
            cout << " ";
        }

        for (int l = i; l > 0; l -= 1) {
            cout << "*";
        }

        cout<<endl;
    }
}

void pattern20(int size){

    for(int i=0;i<size;i+=1){

        if(i == 0 || i==size-1){
            for(int j = 0;j<size;j+=1){
                cout<<"*";
            }
        }
        else{
            cout<<"*";

            for(int l=0;l<size-2;l+=1){
                cout<<"-";
            }

            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern21(int size){

    for(int i=1;i<=size;i+=1){

        for(int j=i;j<=i;j+=1){

            cout<<i;

        }
        cout<<endl;
    }
}

void pattern26(int size){

    for(int i=1;i<=size;i+=1){

        for(int j=i;j<=size;j+=1){

            cout<<i;

        }
        cout<<endl;
    }
}

void pattern28(int size){
    // Upper Half
    for(int i=0;i<size;i+=1){

        for(int j=i;j<size-1;j+=1){
            cout<<' ';
        }

        for(int k=0;k<=i;k+=1){
            cout<<"* ";
        }

        cout<<endl;
    }
    // Lower Half
    for(int i=0;i<size-1;i+=1){

        for(int j=0;j<i+1;j+=1){
            cout<<' ';
        }

        for(int k=size-1;k>i;k-=1){
            cout<<"* ";
        }

        cout<<endl;
    }
}

void pattern30(int size){
    for(int i=1;i<=size;i+=1){

        for(int space=(2*size)-i;space>=i;space-=1){
            cout<<" ";
        }

        for(int j=i;j>=1;j-=1){
            cout<<j<<" ";
        }

        for(int k=2;k<=i;k+=1){
            cout<<k<<" ";
        }
        cout<<endl;
    }
}

void pattern32(char size){

    for(char i=size;i>='A';i-=1){

        for(char j=i;j<=size;j+=1){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern34(char size){

    for(char i=size;i>='A';i-=1){

        for(char j=i;j>='A';j-=1){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern35(int size){

    for(int i=1;i<=size;i+=1){

        for(int j=1;j<=i;j+=1){
            cout<<j;
        }

        for(int k=0;k<(2*size)-(2*i);k+=1){
            cout<<" ";
        }

        for(int l=i;l>0;l-=1){
            cout<<l;
        }

        cout<<endl;
    }
}

int main(){

	cout<<"Welcome to Patterns"<<endl;

	pattern17(5);

	return 0;


}
