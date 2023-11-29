//
// Created by sasha on 9/14/2022.
//

#ifndef PROJECT1_AIR_POLLUTION_H
#define PROJECT1_AIR_POLLUTION_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::string;
using namespace std;

class Air_Pollution {
private:
    string country;
    string city;
    int year;
    double pm;
    double pm10;
    int no2;
    int updatedYear;
    int rowId;

public:
    //constructors
    //default constructor
    Air_Pollution() {
        country = "Country";
        city = "Name";
        year = 3000;
        pm = 0.0;
        pm10 = 0.0;
        no2 = 0;
        updatedYear = 3001;
        rowId = 0;
    }

    //constructor with all parameters
    Air_Pollution(string country, string city, int year, double pm, double pm10, int no2, int updatedYear,
                  int rowId) {
        this->country = country;
        this->city = city;
        this->year = year;
        this->pm = pm;
        this->pm10 = pm10;
        this->no2 = no2;
        this->updatedYear = updatedYear;
        this->rowId = rowId;
    }

    //getters
    string getCountry() const {
        return country;
    }

    string getCity() const {
        return city;
    }

    int getYear() const {
        return year;
    }

    double getPm() const {
        return pm;
    }

    double getPm10() const {
        return pm10;
    }

    int getNo2() const {
        return no2;
    }

    int getUpdatedYear() const {
        return updatedYear;
    }

    int getRowId() const {
        return rowId;
    }

    //setters
    void setCountry(string country) {
        this->country = country;
    }

    void setCity(string city) {
        this->city = city;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setPm(int pm) {
        this->pm = pm;
    }

    void setPm10() {
        this->pm10 = pm10;
    }

    void setNo2() {
        this->pm10 = pm10;
    }

    void setUpdatedYear() {
        this->updatedYear = updatedYear;
    }

    void setRowId() {
        this->rowId = rowId;
    }

    /**
     * Overload stream insertion operator for pretty printing
     */
    friend std::ostream& operator << (std::ostream& outs, const Air_Pollution& pObj) {
        outs << std::fixed
             << std::right
             << std::setprecision(3)
             //<< std::setw(25) << pObj.getCountry()
             << std::left
             //<< "  "
             //<< std::setw(25) << pObj.getCity()
             //<< std::setw(10) << pObj.getYear()
             //<< std::setw(10) << pObj.getPm()
             //<< std::right
             //<< std::setw(10) << pObj.getPm10()
             //<< std::setw(10) << pObj.getNo2()
             //<< std::setw(10) << pObj.getUpdatedYear()
             << std::setw(8) << pObj.getRowId();

        return outs;
    }

    /**
     * Overload < operator for object comparison
     */
    friend bool operator < (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() < rhs.getRowId();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() > rhs.getRowId();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() <= rhs.getRowId();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() >= rhs.getRowId();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() == rhs.getRowId();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Air_Pollution& lhs, const Air_Pollution& rhs) {
        return lhs.getRowId() != rhs.getRowId();
    }
};

void loadFile(string file, vector<Air_Pollution> &objs) {
    ifstream inFile;
    inFile.open(file);

    string heading;
    if (inFile) {
        getline(inFile, heading);
    } else {
        cout << "Could not open file" << endl;
    }
    //declare variables needed for file input
    string country;
    string city;
    int year = 0;
    double pm = 0;
    double pm10 = 0;
    int no2 = 0;
    int updatedYear = 0;
    int rowId = 0;
    char comma;
    //loop until file ends
    while (inFile && inFile.peek() != EOF) {
        //read country
        getline(inFile, country, ',');
        //read city
        getline(inFile, city, ',');
        //read year
        inFile >> year;
        inFile >> comma;
        //read pm
        inFile >> pm;
        if (!inFile) {
            //there was no pm
            pm = -1;
            //clear file
            inFile.clear();
        }
        inFile >> comma;
        //read pm10
        inFile >> pm10;
        if (!inFile) {
            pm10 = -1;
            inFile.clear();
        }
        inFile >> comma;
        //read no2
        inFile >> no2;
        if (!inFile) {
            no2 = -1;
            inFile.clear();
        }
        inFile >> comma;
        //read updated year
        inFile >> updatedYear;
        if (!inFile) {
            updatedYear = -1;
            inFile.clear();
        }
        inFile >> comma;
        //read rowId
        inFile >> rowId;
        //save information and in an Air_Pollution object and add it to the vector pollutionLevels.
        objs.push_back(Air_Pollution(country, city, year, pm, pm10, no2, updatedYear, rowId));
    }
    inFile.close();
    //return true;
}


#endif //PROJECT1_AIR_POLLUTION_H
