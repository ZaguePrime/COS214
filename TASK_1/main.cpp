#include "State.h"
#include "SmartContract.h"
#include "acceptedState.h"
#include "rejectedState.h"
#include "t_acceptedState.h"
#include "completeState.h"
#include "negotiationState.h"
#include "Exception.h"
#include <iostream>
#include <limits>
using namespace std;
//

// KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKK    KKKKKKKWWWWWWWW                           WWWWWWWW
// K:::::::K    K:::::KE::::::::::::::::::::EK:::::::K    K:::::KW::::::W                           W::::::W
// K:::::::K    K:::::KE::::::::::::::::::::EK:::::::K    K:::::KW::::::W                           W::::::W
// K:::::::K   K::::::KEE::::::EEEEEEEEE::::EK:::::::K   K::::::KW::::::W                           W::::::W
// KK::::::K  K:::::KKK  E:::::E       EEEEEEKK::::::K  K:::::KKK W:::::W           WWWWW           W:::::W 
//   K:::::K K:::::K     E:::::E               K:::::K K:::::K     W:::::W         W:::::W         W:::::W  
//   K::::::K:::::K      E::::::EEEEEEEEEE     K::::::K:::::K       W:::::W       W:::::::W       W:::::W   
//   K:::::::::::K       E:::::::::::::::E     K:::::::::::K         W:::::W     W:::::::::W     W:::::W    
//   K:::::::::::K       E:::::::::::::::E     K:::::::::::K          W:::::W   W:::::W:::::W   W:::::W     
//   K::::::K:::::K      E::::::EEEEEEEEEE     K::::::K:::::K          W:::::W W:::::W W:::::W W:::::W      
//   K:::::K K:::::K     E:::::E               K:::::K K:::::K          W:::::W:::::W   W:::::W:::::W       
// KK::::::K  K:::::KKK  E:::::E       EEEEEEKK::::::K  K:::::KKK        W:::::::::W     W:::::::::W        
// K:::::::K   K::::::KEE::::::EEEEEEEE:::::EK:::::::K   K::::::K         W:::::::W       W:::::::W         
// K:::::::K    K:::::KE::::::::::::::::::::EK:::::::K    K:::::K          W:::::W         W:::::W          
// K:::::::K    K:::::KE::::::::::::::::::::EK:::::::K    K:::::K           W:::W           W:::W           
// KKKKKKKKK    KKKKKKKEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKK    KKKKKKK            WWW             WWW           
int main()
{
    int numParties =3;
    SmartContract* contract1 = new SmartContract(numParties,"Child Labour");
    contract1->setState(new negotiationState());
    std::cout<<contract1->toString()<<std::endl;
    int opt = -3;
    while(opt!=6)
    {
        for(int i = 0; i < numParties;i++)
        {
            cout<<"Hello party "<<i+1<<" what would you like to do with the contract?"<<endl;
            cout<<contract1->toString()<<endl;
            cout<<"1. Add condition\n2. Remove Condition\n3. Accept Contract\n4. Reject Contract\n5. Complete Contract\n6. End application"<<endl;
            cin>>opt;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(opt==1)
            {
                try{
                    string con = "";
                    cout<<"Enter the condition you would like to add"<<endl;
                    getline(cin, con);
                    contract1->addCondition(con);
                    cout<<contract1->toString()<<endl;
                }
                catch(Exception e)
                {
                    cout<<e.toString()<<endl;
                }
            }
            else if(opt==2)
            {
                try
                {
                    int num = 0;
                    cout<<contract1->toString()<<endl;
                    cout<<"Enter the condition number you would like to remove"<<endl;
                    cin>>num;
                    contract1->removeCondition(num);
                    cout<<contract1->toString()<<endl;   
                }
                catch(Exception e)
                {
                    cout<<e.toString()<<endl;
                }
            }
            else if(opt==3)
            {
                try
                {
                    contract1->acceptContract();
                    cout<<contract1->toString()<<endl;
                }
                catch(Exception e)
                {
                    cout<<e.toString()<<endl;
                }
                

            }
            else if(opt==4)
            {
                try{
                    contract1->rejectContract();
                    cout<<contract1->toString()<<endl;
                    cout<<"Party "<<i<<" has rejected the contract, L"<<endl;
                    break;
                    opt = 6;
                }

                catch(Exception e)
                {
                    cout<<e.toString()<<endl;
                    opt = 6;
                }
            }
            else if(opt==5)
            {
                try{
                    contract1->completeContract();
                    cout<<contract1->toString()<<endl;
                }
                catch(Exception e)
                {
                    cout<<e.toString()<<endl;
                    opt = 6;
                }

            }
            else{
                opt = 6;
                break;
            }
        }
    }


    return 0;
}