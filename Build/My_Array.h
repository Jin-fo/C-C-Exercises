#include <iostream>
#include <cmath>
class My_Array {
    private:
        static const int MaxValue = 100;
        const float EPSILON = 1e-4;

        int NrValues;
        float array[MaxValue];

        int index;
        float lowest;
        float highest;
        float sum;
        int count;

    public:
        My_Array();
        void add_value(float num);
        void show_low_high();
        void show_high_low();
        float get_high();
        float get_low();
        float get_sum();
        int count_pos();
        bool check_exist(float num);
        void top_five();
    };    

My_Array::My_Array() {
    NrValues = 0;
    index = 0;
};

void My_Array::add_value(float num) {
    if (NrValues < MaxValue) {
        array[NrValues] = num;
        NrValues++;
        
    } else {
        std::cout << "[!]Out of Bound Error: Array is full";
    }
    
};
void My_Array::show_low_high() {
    if (index < NrValues) {
        for (int i = 0; i<NrValues-index-1; i++)
            if(array[i] < array[i+1]) {
                float temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
        }
        index++;
        std::cout << "\n\t" << array[NrValues-index];
        return show_low_high();
    }
    index = 0;
};
//
void My_Array::show_high_low() {
    if (index < NrValues) {
        for (int i = 0; i<NrValues-1; i++)
            if(array[i] > array[i+1]) {
                float temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
        }
        index++;
        std::cout << "\n\t" << array[NrValues-index];
        return show_high_low();
    }
    index = 0;
};

float My_Array::get_low() {
    if (index == 0) {
        lowest = array[0];
        index++;
    } 

    if (index < NrValues) {
        if (array[index] < lowest) {
            lowest = array[index];
        }
        index ++;
        return get_low();
    }
    index = 0;
    return lowest;
};

float My_Array::get_high() {
    if (index == 0) {
        highest = array[0];
        index++;
    } 

    if (index < NrValues) {
        if (array[index] > highest) {
            highest = array[index];
        } 
        index ++;
        return get_high();
    } 
    index = 0;
    return highest;
};

float My_Array::get_sum() {
    if (index == 0) {
        sum = array[0];
        index++;
    }
    if (index < NrValues) {
        sum += array[index];
        index++;
        return get_sum();
    }
    index = 0;
    return sum;
};

bool My_Array::check_exist(float num) {
    if (index < NrValues) {
        if (fabs(array[index] - num) < EPSILON) { //Epsilon to accuratly perform decimal comparison
            return true;
        }
        index++;
        return check_exist(num);
    }
    index = 0;
    return false;
};

int My_Array::count_pos() {
    if (index == 0) {
        count = 0;
    }
    if (index < NrValues) {
        if (array[index] > 0) {
            count++;
        }
        index++;
        return count_pos();
    } 
    index = 0;
    return count;
};

//HW part 3: 
//Extend the lab exercise 3 to include a recursive method that finds the five largest values in the
//array assuming that there are five or more values in the array.
void My_Array::top_five() {
};



