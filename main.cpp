#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Excursion{
    private:
        string name;
        string time;
        string guide;
        int age;
    public:
        Excursion(string name_n, string time_n, string guide_n, int age_n){
            name = name_n;
            time = time_n;
            guide = guide_n;
            age = age_n;
        }
        ~Excursion(){}
        virtual void displayInfo() const{
            cout << "Excursion " << name << " " << time << " " << guide << " " << age << endl;
        }
        void displayInfostr(ofstream& stream) const{
            cout << "Excursion " << name << " " << time << " " << guide << " " << age << endl;
            stream << "Excursion " << name << " " << time << " " << guide << " " << age << endl;
        }
        int getTime() const{
            string temp;
            temp = time.substr(0,2) + time.substr(3,5);
            return stoi(temp);
        }
        string getName() const{
            return name;
        }
        string getGuide() const{
            return guide;
        }
        void modifyGuide(string opt1){
            guide = opt1;
        }
        int getAge() const{
            return age;
        }
};

template <typename T1, typename T2>
class Pair {
    private:
        T1 first;
        T2 second;
    public:
        void displayPair() const{
            cout<<first<<" "<<second<<endl;
        }
};

class HistoricalTour: public Excursion{
    private:
        string hist_place;
    public:
        HistoricalTour(string name_n, string time_n, string guide_n, string hist_place_n, int age_n): Excursion(name_n, time_n, guide_n, age_n){
            hist_place = hist_place_n;
        }
        ~HistoricalTour(){};
        void displayInfo() const override{
            Excursion::displayInfo();
            cout << "Hist " << hist_place << endl;
        }
};

class CitySightseeing: public Excursion{
    private:
        string city_place;
    public:
        CitySightseeing(string name_n, string time_n, string guide_n, string city_place_n, int age_n): Excursion(name_n, time_n, guide_n, age_n){
            city_place = city_place_n;
        }
        ~CitySightseeing(){};
        void displayInfo() const override{
            Excursion::displayInfo();
            cout << "City " << city_place << endl;
        }
};

template <typename Container>
inline void add(Container& container, string opt1, string opt2, string opt3, int opt4) {
    container.push_back(Excursion(opt1,opt2,opt3,opt4));
}

template <typename Container>
inline void search(Container& container, string opt1, ofstream& stream){
    for(const auto& i: container){
		if(i.getGuide() == opt1){
            i.displayInfostr(stream);
        }
	}
}

template <typename Container>
inline void sort(Container& container){
    sort(container.begin(), container.end(), [](const Excursion& a, const Excursion& b) { return a.getTime() < b.getTime(); });
}

template <typename Container>
inline void editguide(Container& container, ofstream& stream){
    int counter = 1;
    string temp, temp1;
    for(const auto& i: container){
        cout << counter << ": ";
		i.displayInfostr(stream);
        counter++;
	}
    cout << "What exc(number) do you want to modif?" << endl;
    stream << "What exc do you want to modif?" << endl;
    cin >> temp;
    stream << temp << endl;
    cout << "New name?" << endl;
    stream << "New name?" << endl;
    cin >> temp1;
    stream << temp1 << endl;
    container[stoi(temp)-1].modifyGuide(temp1);
}

int main(){
    vector<Excursion> db = vector<Excursion>{};
    // db.push_back(Excursion("test","12:00","test2",12));
    // db.push_back(Excursion("test3","12:00","test4",8));
    // db.push_back(Excursion("test5","12:00","test6",20));
    ofstream logFile("output.txt");
    if (logFile.is_open()){
        cout << "File opened" << endl; 
        logFile << "start" << endl;
    }
    else{
        cout << "Error file output";
        return 1;
    }
    bool work = true;
    string option;
    string opt1, opt2, opt3, opt4;
    while(work){
        cout << "Menu:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Search" << endl;
        cout << "3. Sort" << endl;
        cout << "4. Output" << endl;
        cout << "5. Edit guide" << endl;
        cout << "6. Search for some age" << endl;
        cout << "7. Exit" << endl;
		logFile << "Menu:" << endl;
        logFile << "1. Add" << endl;
        logFile << "2. Search" << endl;
        logFile << "3. Sort" << endl;
        logFile << "4. Output" << endl;
        logFile << "5. Edit guide" << endl;
        logFile << "6. Search for some age" << endl;
        logFile << "7. Exit" << endl;
        cin >> option;
        logFile << option << endl;
        switch (stoi(option))
        {
        case 1:
            cout << "Adding" << endl;
            logFile << "Adding" << endl;
            cout << "Write info in format:\nName \nTime(xx:xx) \nGuide" << endl;
            logFile << "Write info in format:\nName \nTime(xx:xx) \nGuide" << endl;
            cin >> opt1;
            logFile << opt1 << endl;
            cin >> opt2;
            logFile << opt2 << endl;
            cin >> opt3;
            logFile << opt3 << endl;
            cin >> opt4;
            logFile << opt4 << endl;
            add(db, opt1, opt2, opt3, stoi(opt4));
            cout << "Added" << endl;
            logFile << "Added" << endl;
            break;
        case 2:
            cout << "Searching" << endl;
            logFile << "Searching" << endl;
            cout << "Write name guide:\nGuide:" ;
            logFile << "Write name guide:\nGuide:";
            cin >> opt1;
            logFile << opt1 << endl;
            search(db, opt1, logFile);
            cout << "Searched" << endl;
            logFile << "Searched" << endl;
            break;
        case 3:
            cout << "Sorting" << endl;
            logFile << "Sorting" << endl;
            sort(db);
            cout << "Sorted" << endl;
            logFile << "Sorted" << endl;
            for(const auto& i: db){
		        i.displayInfostr(logFile);
	        }
            break;
        case 4:
            cout << "Output" << endl;
            logFile << "Output" << endl;
            for(const auto& i: db){
		        i.displayInfostr(logFile);
	        }
            break;
        case 5:
            cout << "Edit guide" << endl;
            logFile << "Edit guide" << endl;
            editguide(db, logFile);
            cout << "Edited" << endl;
            logFile << "Edited" << endl;
            break;
        case 6:
            cout << "For what age?" << endl;
            logFile << "For what age?" << endl;
            cin >> opt1;
            logFile << opt1 << endl;
            for(const auto& i: db){
		        if(stoi(opt1) >= i.getAge()){
                    i.displayInfostr(logFile);
                }
	        }
            cout << "Searched" << endl;
            logFile << "Searched" << endl;
            break;
        case 7:
            cout << "Exit. goodbye" << endl;
            logFile << "Exit. goodbye" << endl;
            work = false;
            logFile.close();
            break;
        default:
            cout << "err" << endl;
            logFile << "err" << endl;
            work = false;
            logFile.close();
            break;
        }
    }
    db.erase(db.begin(), db.end());
    return 0;
}