#include<iostream>
#define SIZE 10

using namespace std;

class stacks
{
    int arr[SIZE],counter=0;
public:
    stacks(){for(int i=0;i<SIZE;i++) arr[i]=0;};
    int push(int);
    int pop(void);
    void display(void);
};

void stacks::display(void)
{
    for(int i=0;i<counter;i++)
        cout<<arr[i]<<"  ";
}

int stacks::pop(void)
{
    int result=0;
    if(counter!=0)
    {
        counter--;
        cout<<arr[counter];
        result=1;
    }
    return result;
}

int stacks::push(int n)
{
    int result=0;
    if(counter!=10)
    {
        arr[counter]=n;
        counter++;
        result=1;
    }
    return result;
}

main()
{
    stacks st;
    char op='y';
    while(op=='y'||op=='Y')
    {
        cout<<"\nPress 1 to push";
        cout<<"\nPress 2 to pop";
        cout<<"\nPress 3 to display ";
        int opt;
        cin>>opt;
        switch(opt)
        {
            int result;
        case 1:
            {
                cout<<"\nEnter a data ";
                cin>>result;
                result=st.push(result);
                if(result)
                    cout<<"\nNo. entered successfully";
                else cout<<"\nStack Overflow";
                break;
            }
        case 2:
            {
                result=st.pop();
                if(result)
                    cout<<"\nNo. deleted successfully";
                else cout<<"\nStack Underflow";
                break;
            }
        case 3:
            {
                cout<<endl;
                st.display();
                break;
            }
        default:
            cout<<"\nInvalid option chosen.";
        }
        cout<<"\nDo you want to continue??....y/Y ";
        //fflush(stdin);
        cin>>op;
    }
}
