//
//  medium.cpp
//  project3
//
//  Created by Zach Qian on 5/1/19.
//  Copyright © 2019 Zach Qian. All rights reserved.
//

//#include <stdio.h>
//#include <iostream>
//#include <string>
//using namespace std;
//
//enum CallType {
//    VOICE, TEXT
//};

//Your declarations and implementations would go here

class Medium{
public:
    Medium(std::string ID): m_ID(ID){};
    virtual std::string connect() const = 0;
    virtual std::string transmit(std::string msg) const{
        return "text: " + msg;
    }
    std::string id() const{return m_ID;}
    virtual ~Medium(){}
private:
    std::string m_ID;
    
};

class TwitterAccount: public Medium
{
public:
    TwitterAccount(std::string username): Medium(username){};
    virtual std::string connect() const{
        return "Tweet";
    }

    virtual ~TwitterAccount(){
        std::cout << "Destroying the Twitter account " << this->id()<< "." << std::endl;
    }
};

class Phone: public Medium{
public:
    Phone(std::string pNum, CallType type): Medium(pNum),m_type(type){};
    virtual std::string connect() const{
        return "Call";
    }
    virtual std::string transmit(std::string msg) const{
        if(m_type ==  VOICE)
            return "voice: " + msg;
        else
            return Medium::transmit(msg);
    }
    virtual ~Phone(){
        std::cout << "Destroying the phone " << this->id()<< "." << std::endl;

    }
private:
    CallType m_type;

};

class EmailAccount: public Medium{
public:
    EmailAccount(std::string handle): Medium(handle){};
    virtual std::string connect() const{
        return "Email";
    }
    virtual ~EmailAccount(){
        std::cout << "Destroying the email account " << this->id()<< "." << std::endl;

    }
};


//
//void send(const Medium* m, string msg)
//{
//    cout << m->connect() << " using id " << m->id()
//    << ", sending " << m->transmit(msg) << endl;
//}
//
//int main()
//{
////    Medium temp("ethel");
//    Medium* media[4];
//    media[0] = new TwitterAccount("UCLABruinAlert");
//    // Phone users may prefer messages to be left as voice or text.
//    media[1] = new Phone("(310) 825 3894", VOICE);
//    media[2] = new Phone("(213) 389 9060", TEXT);
//    media[3] = new EmailAccount("jbroon@ucla.edu");
//
//    cout << "Send the message." << endl;
//    for (int k = 0; k < 4; k++)
//        send(media[k], "Major power outage in West L.A.");
//
//    // Clean up the media before exiting
//    cout << "Cleaning up." << endl;
//    for (int k = 0; k < 4; k++)
//        delete media[k];
//    return 0;
//}
