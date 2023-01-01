#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <ctime>

#define regNo_len 10
#define make_len 30
#define engineNo_len 20
#define vehicleModel_len 30
#define bodyType_len 20
#define ownerName_len 50
#define vehicleClass_len 10

#define fileName "records.bin"

#define alphabetCount 26
#define numCount 10
#define alphaNumCount 36

using namespace std;

const char * monthNames[] = {"January", "Februray", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void stringCapitalize(char * arr, const int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] >= 97 && arr[i] <= 122)
            arr[i] = toupper(arr[i]);
    }
        
}

class Date {
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;

public:

    Date() { }
    
    void setDate(unsigned short int day, unsigned short int month, unsigned short int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(unsigned short int day, unsigned short int month, unsigned short int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    friend ostream& operator << (ostream &os, Date &date);
    friend istream& operator >> (istream &is, Date &date);
};

ostream& operator << (ostream &os, Date &date)
{
    cout<<monthNames[date.month-1]<<" "<<date.day<<", "<<date.year;
    return os;
}

istream& operator >> (istream &is, Date &date)
{
    scanf_s("%hu/%hu/%hu",&date.day,&date.month,&date.year);
    return is;
}


class User {
    char regNo[regNo_len];
    char make[make_len];
    Date regDate;
    Date taxPayment;
    char engineNo[engineNo_len];
    char vehicleModel[vehicleModel_len];
    char bodyType[bodyType_len];
    char ownerName[ownerName_len];
    unsigned short int modelYear;
    short unsigned int seatingCapacity;
    bool CPLC;
    short unsigned int horsePower;
    char vehicleClass[vehicleClass_len];

public:

    User() { }

    User(char (&regNo)[regNo_len], char (&make)[make_len], Date regDate, Date taxPayment, char (&engineNo)[engineNo_len], char (&vehicleModel)[vehicleModel_len], char (&bodyType)[bodyType_len], char (&ownerName)[ownerName_len], unsigned short int modelYear, short unsigned int seatingCapacity, bool CPLC, short unsigned int horsePower, char (&vehicleClass)[vehicleClass_len])
    {
        strcpy_s(this->regNo,regNo);
        strcpy_s(this->make,make);
        this->regDate = regDate;
        this->taxPayment = taxPayment;
        strcpy_s(this->engineNo,engineNo);
        strcpy_s(this->vehicleModel,vehicleModel);
        strcpy_s(this->bodyType,bodyType);
        strcpy_s(this->ownerName,ownerName);
        this->modelYear = modelYear;
        this->seatingCapacity = seatingCapacity;
        this->CPLC = CPLC;
        this->horsePower = horsePower;
        strcpy_s(this->vehicleClass,vehicleClass);

        stringCapitalize(this->regNo,regNo_len);
        stringCapitalize(this->make,make_len);
        stringCapitalize(this->engineNo,engineNo_len);
        stringCapitalize(this->vehicleModel,vehicleModel_len);
        stringCapitalize(this->bodyType,bodyType_len);
        stringCapitalize(this->ownerName,ownerName_len);
        stringCapitalize(this->vehicleClass,vehicleClass_len);
    }
    
    void setRegNo(char (&regNo)[regNo_len])
    {
        strcpy_s(this->regNo,regNo);
    }

    void setMake(char (&make)[make_len])
    {
        strcpy_s(this->make,make);
    }

    void setRegDate(Date regDate)
    {
        this->regDate = regDate;
    }

    void setTaxPayment(Date taxPayment)
    {
        this->taxPayment = taxPayment;
    }

    void setEngineNo(char (&engineNo)[engineNo_len])
    {
        strcpy_s(this->engineNo,engineNo);
    }

    void SetVehicleModel(char (&vehicleModel)[vehicleModel_len])
    {
        strcpy_s(this->vehicleModel,vehicleModel);
    }

    void setBodyType(char (&bodyType)[bodyType_len])
    {
        strcpy_s(this->bodyType,bodyType);
    }

    void setOwnerName(char (&ownerName)[ownerName_len])
    {
        strcpy_s(this->ownerName,ownerName);
    }
    
    void setModelYear(unsigned short int modelYear)
    {
        this->modelYear = modelYear;
    }

    void setSeatingCapacity(unsigned short int seatingCapacity)
    {
        this->seatingCapacity = seatingCapacity;
    }

    void setCPLC(bool CPLC)
    {
        this->CPLC = CPLC;
    }

    void setHorsePower(unsigned short int horsePower)
    {
        this->horsePower = horsePower;
    }

    void setVehicleClass(char (&vehicleClass)[vehicleClass_len])
    {
        strcpy_s(this->vehicleClass,vehicleClass);
    }

    const char * const getRegNo()
    {
        return this->regNo;
    }

    friend ostream& operator << (ostream &os, User &user);
    friend istream& operator >> (istream &is, User &user);
};

ostream& operator << (ostream &os, User &user)
{
    cout<<"-----------------------------------"<<endl;
    cout<<"Registration No: "<<user.regNo<<endl<<"Make: "<<user.make<<endl;
    cout<<"Registration Date: "<<user.regDate<<endl<<"Tax Payment: "<<user.taxPayment<<endl;
    cout<<"Engine No: "<<user.engineNo<<endl<<"Vehicle Model: "<<user.vehicleModel<<endl;
    cout<<"Body Type: "<<user.bodyType<<endl<<"Owner Name: "<<user.ownerName<<endl;
    cout<<"Model Year: "<<user.modelYear<<endl<<"Seating Capacity: "<<user.seatingCapacity<<endl;
    cout<<"CPLC: ";
    if(user.CPLC)
        cout<<"Vehicle is Clear";
    else   
        cout<<"Vehicle is not Clear";
    cout<<endl<<"Horse Power: "<<user.horsePower<<endl<<"Class of Vehicle: "<<user.vehicleClass<<endl;
    cout<<"-----------------------------------"<<endl;
    return os;
}

istream& operator >> (istream &is, User &user)
{
    cout<<"-----------------------------------"<<endl;
    cout<<"Registration No: "; cin.getline(user.regNo,regNo_len);
    cout<<"Make: "; cin.getline(user.make,make_len);
    cout<<"Registration Date (dd/mm/yy): "; cin>>user.regDate;
    cout<<"Tax Payment (dd/mm/yy): "; cin>>user.taxPayment;
    cin.ignore();
    cout<<"Engine No: "; cin.getline(user.engineNo,engineNo_len);
    cout<<"Vehicle Model: "; cin.getline(user.vehicleModel,vehicleModel_len);
    cout<<"Body Type: "; cin.getline(user.bodyType,bodyType_len);
    cout<<"Owners' Name: "; cin.getline(user.ownerName,ownerName_len);
    cin.clear();
    cout<<"Model Year: "; cin>>user.modelYear;
    cout<<"Seating Capacity: "; cin>>user.seatingCapacity;
    cout<<"CPLC (1 = YES, 2 = NO): "; cin>>user.CPLC;
    cout<<"Horse Power: "; cin>>user.horsePower;
    cin.ignore();
    cout<<"Class of Vehicle: "; cin.getline(user.vehicleClass,vehicleClass_len);
    cout<<"-----------------------------------"<<endl;

    stringCapitalize(user.regNo,regNo_len);
    stringCapitalize(user.make,make_len);
    stringCapitalize(user.engineNo,engineNo_len);
    stringCapitalize(user.vehicleModel,vehicleModel_len);
    stringCapitalize(user.bodyType,bodyType_len);
    stringCapitalize(user.ownerName,ownerName_len);
    stringCapitalize(user.vehicleClass,vehicleClass_len);
    return is;
}

class Node {
public:
    char ch;
    User * data;
    Node * children[alphaNumCount];

    Node(char ch)
    {
        this->ch = ch;
        for(int i = 0 ; i < alphaNumCount ; i++)
            this->children[i] = NULL;
        data = NULL;
    }
};

class Tree {
    friend class UI;
    Node * root;

public:

    Tree()
    {
        this->root = new Node('*');
    }

    void insert(string numPlate, User &data)
    {
        Node * current = this->root;
        for(int i = 0 ; i <= numPlate.length() ; i++)
        {
            if(numPlate[i] >= 65 && numPlate[i] <= 90)
            {
                if(current->children[numPlate[i]-65] == NULL)
                    current->children[numPlate[i]-65] = new Node(numPlate[i]);         
               
                current = current->children[numPlate[i]-65];
            }    
            else if(numPlate[i] >= 48 && numPlate[i] <= 57)
            {
                if(current->children[alphabetCount+numPlate[i]-48] == NULL)
                    current->children[alphabetCount+numPlate[i]-48] = new Node(numPlate[i]);
                
                current = current->children[alphabetCount+numPlate[i]-48];
            }
        }

        if(current->data == NULL)
            current->data = new User(data);
            
    }

    void userInfo(string numPlate)
    {
        User * user = search(numPlate);
        if(user == NULL)
        {
            cout<<"Not Found!\n";
            return;
        }

        cout<<*user;
    }

    void print()
    {
        this->print(this->root);
    }

    void recordsPrint()
    {
        this->recordsPrint(this->root);
    }

protected:

    Node* searchNode(string numPlate)
    {
        Node * current = this->root;
        bool isFound = true;
        for(int i = 0 ; i < numPlate.length() ; i++)
        {
            if(numPlate[i] >= 65 && numPlate[i] <= 90)
            {
                if(current->children[numPlate[i]-65] == NULL)
                {
                    isFound = false; 
                    break;
                }
                current = current->children[numPlate[i]-65];
            }
            else if(numPlate[i] >= 48 && numPlate[i] <= 57)
            {
                if(current->children[alphabetCount+numPlate[i]-48] == NULL)
                {
                    isFound = false;
                    break;
                }
                current = current->children[alphabetCount+numPlate[i]-48];
            }
        }

        if(!isFound)
            return NULL;

        return current;
    }

    User* search(string numPlate)
    {
        Node * current = searchNode(numPlate);
        if(current == NULL)
            return NULL;
        else
            return current->data;
    }

    void print(Node * current)
    {
        if(current == NULL)
            return;
        
        cout<<current->ch<<" ";

        for(int i = 0 ; i < alphaNumCount; i++)
            print(current->children[i]);
    }

    void recordsPrint(Node * current)
    {
        if(current == NULL)
            return;

        if(current->data != NULL)
            cout<<*current->data<<endl;
        
        for(int i = 0 ; i < alphaNumCount ; i++)
            recordsPrint(current->children[i]);
    }
};

class UI {
    Tree records;

public:

    UI()
    {
        system("title License Plate Recognition");
        system("color F0");
        ifstream fin(fileName,ios::in);

        if(!fin)
            return;

        User user;

        while(1) 
        {
            fin.read((char*)&user,sizeof(user));
            if(fin.eof())
                break;
            records.insert(user.getRegNo(),user);
        }

        fin.close();
    }

    void menu()
    {
        while(1)
        {
            system("cls");
            cout << "***********************\n";
            cout<<"1- Add Record"<<endl;
            cout<<"2- Search by Plate No."<<endl;
            cout <<"3- Search by Image" <<endl;
            cout<<"4- Update Record"<<endl;
            cout <<"5- See all Records" <<endl;
            cout<<"0- Exit"<<endl<<endl;
        
            short int option;

            do {
                cout<<"Enter option: ";
                cin>>option;
            } while(option<0 || option>5);

            cin.clear();
            cin.ignore();
            system("cls");
            switch(option)
            {
                case 1: {
                    User user;
                    cin>>user;
                    if(records.search(user.getRegNo()) == NULL)
                    {
                        if(addRecord(user))
                        {
                            records.insert(user.getRegNo(),user);
                            cout<<"Record Added Successfully!";
                        }
                    }
                    else
                        cout<<"Record exists!";
                }
                break;
                case 2: {
                    char regNo[regNo_len];
                    cout<<"Reg. No. to Search: ";
                    cin.getline(regNo,regNo_len);
                    stringCapitalize(regNo,regNo_len);
                    User * user = records.search(regNo);
                    if(user!=NULL)
                        cout<<*user;
                    else
                        cout<<"Registration No."<<regNo<<" not found!";
                }
                break;
                case 3: {
                    string dir;
                    cout<<"Enter Image Path With Extension: ";
                    cin>>dir;
                    searchByImage(dir);
                }
                break;
                case 4: {
                    char regNo[regNo_len];
                    cout<<"Reg. No. to modify: ";
                    cin.getline(regNo,regNo_len);
                    stringCapitalize(regNo,regNo_len);
                    User * user = records.search(regNo);
                    if(user != NULL) 
                    {
                        User temp(*user);
                        if(modifyRecord(*user))
                        {
                            if(!updateRecord(*user))
                                *user = temp;
                        }
                    }
                    else
                        cout<<"Registration No."<<regNo<<" not found!"; 
                }
                break;
                case 5: {
                    records.recordsPrint();
                }
                break;
                case 0: exit(0);
            }
            menuReturn(0);
        }
        return;
    }

private:

    bool modifyRecord(User &user)
    {
        bool modified = false;
        while(1)
        {
            system("cls");
            cout<<user<<endl<<endl;
            cout<<"1- Tax Payment Date"<<endl<<"2- Engine No"<<endl<<"3- Body Type"<<endl;
            cout<<"4- Owner's Name"<<endl<<"5- CPLC"<<endl<<"6- Horse Power"<<endl;
            cout<<"7- Class of Vehicle"<<endl<<"0- Return"<<endl<<endl;

            short int option;

            do {
                cout<<"Enter option: ";
                cin>>option;
            } while(option<0 || option>7);

            if(option!=0)
                modified = true;

            cin.clear();
            cin.ignore();
            switch(option)
            {
                case 1: {
                    cout<<"Updated Tax Payment Date (dd/mm/yy): ";
                    Date date;
                    cin>>date;
                    user.setTaxPayment(date);
                    menuReturn(1);
                }
                break;
                case 2: {
                    cout<<"Updated Engine No: ";
                    char engineNo[engineNo_len];
                    cin.getline(engineNo,engineNo_len);
                    stringCapitalize(engineNo,engineNo_len);
                    user.setEngineNo(engineNo);
                    menuReturn(1);
                }
                break;
                case 3: {
                    cout<<"Updated Body Type: ";
                    char bodyType[bodyType_len];
                    cin.getline(bodyType,bodyType_len);
                    stringCapitalize(bodyType,bodyType_len);
                    user.setBodyType(bodyType);
                    menuReturn(1);
                }
                break;
                case 4: {
                    cout<<"Updated Owner's Name: ";
                    char ownerName[ownerName_len];
                    cin.getline(ownerName,ownerName_len);
                    stringCapitalize(ownerName,ownerName_len);
                    user.setOwnerName(ownerName);
                    menuReturn(1);
                }
                break;
                case 5: {
                    cout<<"Updated CPLC Status (1 = YES, 2 = NO): ";
                    bool CPLC;
                    cin>>CPLC;
                    user.setCPLC(CPLC);
                    menuReturn(1);
                }
                break;
                case 6: {
                    cout<<"Updated Horse Power: ";
                    unsigned short int horsePower;
                    cin>>horsePower;
                    user.setHorsePower(horsePower);
                    menuReturn(1);
                }
                break;
                case 7: {
                    cout<<"Updated Vehicle Class: ";
                    char vehicleClass[vehicleClass_len];
                    cin.getline(vehicleClass,vehicleClass_len);
                    stringCapitalize(vehicleClass,vehicleClass_len);
                    user.setVehicleClass(vehicleClass);
                    menuReturn(1);
                }
                break;
                case 0: {
                    return modified;
                }
                break;
            }
        }
    }

    bool addRecord(User &user)
    {
        ofstream fout(fileName,ios::app);
        if(!fout)
        {
            cout<<"File permission error!";
            return false;
        }
        fout.write((char*)&user,sizeof(user));
        fout.close();
        return true;
    }

    bool updateRecord(User &user)
    {
        ofstream fout("temp.bin",ios::app);
        if(!fout)
        {
            cout<<"File permission error!";
            return false;
        }

        ifstream fin(fileName,ios::in);
        if(!fin)
        {
            cout<<"Error reading file!";
            return false;
        }

        User rW;
        bool found = false;
        
        while(1)
        {
            fin.read((char*)&rW,sizeof(rW));
            
            if(fin.eof())
                break;

            if(found == false)
            {   
                if(strcmp(user.getRegNo(),rW.getRegNo()) == 0)
                {
                    fout.write((char*)&user,sizeof(user));
                    found = true;
                    continue;
                }
            }
            fout.write((char*)&rW,sizeof(rW));  
        }

        fin.close();
        fout.close();
        remove(fileName);
        rename("temp.bin", fileName);
        return true;
    }

    bool validateNumPlate(string numPlate)
    {
        for (int i = 0; i < numPlate.length(); i++)
        {
            if (numPlate[i] < 48 || (numPlate[i] > 57 && numPlate[i] < 65))
                return false;
            else if (numPlate[i] > 90)
                return false;
        }
        return true;
    }

    void menuReturn(int num)
    {
        if(num == 1)
            cout<<"Updated successfully!";

        cout<<endl<<endl<<"Press any key to ";
        if(num == 0)
            cout<<"return";
        else if(num == 1)
            cout<<"continue";

        cout<<".";
        _getch();
        return;
    }

    bool searchByImage(string dir)
    {
        string numPlate = convertImageToString(dir);
        
        if (!validateNumPlate(numPlate))
        {
            cout << "Invalid License Plate!\n";
            return false;
        }

        if (numPlate.length() != 0)
        {
            User* user = records.search(numPlate);
            if (user == NULL)
            {
                cout << "Record not found!\n";
                return false;
            }
            cout << *user;
        }
    }

    string convertImageToString(string dir)
    {
        std::string numPlate;

        bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();          

        if (blnKNNTrainingSuccessful == false) {                            
                                                                            
            std::cout << std::endl << std::endl << "error: error: KNN traning was not successful" << std::endl << std::endl;
            return "";                                                      
        }

        cv::Mat imgOriginalScene;          

        imgOriginalScene = cv::imread(dir);        

        if (imgOriginalScene.empty()) {                             
            std::cout << "error: image not read from file\n\n";                                               
            return "";                                             
        }

        std::vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene);          

        vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates);                               

        //cv::imshow("imgOriginalScene", imgOriginalScene);           

        if (vectorOfPossiblePlates.empty()) {                                              
            std::cout << std::endl << "no license plates were detected" << std::endl;       
        }
        else {                                                                            
                                                                                          
                                                                                         
            std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);

            PossiblePlate licPlate = vectorOfPossiblePlates.front();

            //cv::imshow("imgPlate", licPlate.imgPlate);           
            //cv::imshow("imgThresh", licPlate.imgThresh);

            if (licPlate.strChars.length() == 0) {                                                      
                std::cout << std::endl << "no characters were detected" << std::endl << std::endl;      
                return "";                                                                              
            }

            drawRedRectangleAroundPlate(imgOriginalScene, licPlate);              

            std::cout << std::endl << "license plate read from image = " << licPlate.strChars << std::endl;    
            //std::cout << std::endl << "-----------------------------------------" << std::endl;
            numPlate = licPlate.strChars;

            writeLicensePlateCharsOnImage(imgOriginalScene, licPlate);            

            //cv::imshow("imgOriginalScene", imgOriginalScene);                       

            //cv::imwrite("imgOriginalScene.png", imgOriginalScene);                  
        }

        cv::waitKey(0);

        return numPlate;
    }

};

