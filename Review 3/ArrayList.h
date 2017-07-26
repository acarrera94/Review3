/********************************************
 *** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
 *** Andre Carrera
 ***
 ********************************************/

// You may modify any part of this file, but you must not change the name of the
// class or any of the method declarations.  If you do, your project will not
// compile.

#pragma once

#include <exception>

using namespace std;

namespace cs235 {//in the right place?
    
    template <typename T>
    class ArrayList
    {
    private:
        // Declare your private variables here.  You'll need:
        // 1. An array to store your data.
        static const int MAXCAPACITY = 10;
        T dataArray[MAXCAPACITY];
        // 2. A constant value to store the max capacity of your array (no magic
        //    numbers).  The maximum capacity for your list should be 10.
        
        // 3. A field to keep track of how many items are in your list.
        size_t counter;
        
    public:
        
        // Delete the throw-statement in the body of this constructor, and
        // initialize the fields in your class.  Remember to use a member-initializer
        // list.  Don't remember what a member-initializer list is?  Google can
        // help.  Do a search for:
        //     C++ member initializer list
        // (Google is a programmer's best friend)
        ArrayList()//not sure if I'm doing it right
        {
            counter = 0;
            
            // TODO: delete this line, and put your code here.
        }
        
        
        // This method should add a value onto the end of the list.  Make sure there
        // is room for the new item (DO NOT overflow the end of the list).
        //
        // If there is no room left in the list, return false.  If there is room,
        // append the new item and return true.
        void Append(const T& value)
        {
            // TODO: delete this line, and put your code here.
            if (counter< MAXCAPACITY){
                dataArray[counter++] = value;
            }else
            {
                throw "More than max";
            }
            
        }
        
        
        // This method should remove all the contents of the array.  You don't have
        // to do much here.  Just set the current count to zero, and call it good.
        // You don't have to zero out the contents of your array, since you never
        // look at any element beyond where the current count is pointing.
        void Clear()
        {
            // TODO: delete this line, and put your code here.
            counter = 0;
        }
        
        
        // This method should return the maximum capacity for your list.
        size_t GetCapacity()
        {
            // TODO: delete this line, and put your code here.
            return MAXCAPACITY;
        }
        
        
        // This method should provide an up-to-date count of how many items are
        // stored in your list.  When your list is first created, this should return
        // zero.  Whenever you add or remove a value, this method should get updated
        // accordingly.
        size_t GetCount()
        {
            // TODO: delete this line, and put your code here.
            return counter;
        }
        
        
        // This should get a value at the position indicated by pos.  For instance,
        // If I have an array of {8, 3, 7, 2}, and I want to get the value at
        // position 3, this method should return a value of 7.  If pos is greater
        // than or equal to the current count, this method should return a value of
        // zero (we'll learn how to do better error handling in a future lecture).
        T GetValue(size_t pos)
        {
            // TODO: delete this line, and put your code here.
            if(pos <counter){
                T currentNum = dataArray[pos];//looking at the code I think it means at the array value, not user value
                return currentNum;
                
            }
            else {
                //return 0;
                throw "Trying to get something other than position";
            }
        }
        
        
        // This method should insert a new element into the array.  The value for
        // pos can be less than or equal to GetCount.  If pos is equal to GetCount,
        // then this method will append the item to the end of the array.  If pos
        // is less than GetCount, then this method will scroll all the elements
        // right, starting at pos, and insert the new element.  For example, if I
        // have an array of {7, 3, 8, 2}, and I want to insert the value 6 at
        // position 2, I will end up with {7, 3, 6, 8, 2}.  If there is not enough
        // capacity to insert a new value, return a false.  Otherwise return a
        // value of true.
        void InsertAt(const size_t& pos, const T& value)//what is size_t, should i use this instead of counter?
        {
            // TODO: delete this line, and put your code here.
            if(counter ==MAXCAPACITY){
                throw "At max capacity";
            }
            else if (pos==GetCount()) {//what does pos mean?
                Append(value);
                //return true;
            }
            else if(pos<GetCount()){
                T tempOne = value;//save temp number
                T tempTwo = 0;
                for (size_t count = pos; count<= counter; count++) {
                    
                    tempTwo = dataArray[count];//save next temp number
                    dataArray[count] = tempOne;
                    tempOne = tempTwo;
                }
                counter++;
                //return true;
            }
            else{
                throw "some other error";
                //return something
            }
        }
        
        
        // This method should remove a value from an arbitrary position in the list.
        // If the position is beyond the end of the list, then do nothing and return
        // a value of false.  If the position is less than the current count, then
        // remove the item and return a value of true.
        //
        // When removing an item, you MUST NOT leave a hole in the array.  You must
        // copy the trailing elements over one space.  For example, if my array has
        // values {7, 3, 8, 2}, and I want to remove the value at position 1, I need
        // to move the 8 and the 2 each one element to the left, so I have {7, 8, 2}.
        void RemoveAt(size_t pos)
        {
            const int EMPTY = 0;
            if(GetCount()==EMPTY){
                throw "Thing is empyt";
                //return false;
            }
            else if(pos<GetCount()){
                const int NEXTNUM = 1;
                for (size_t removeCount = pos; removeCount<GetCount(); removeCount++) {
                    dataArray[removeCount]= dataArray[removeCount+NEXTNUM];
                }
                counter--;
                //return true;
                
            }
            else {
                throw "Invalid position";
                //return false;
            }
        }
        
        
        // This method should replace a value at a given position.  The value in pos
        // MUST be less than the current count of items in the array.  If pos is >=
        // the current count, return a value of false.  Otherwise return a value of
        // true.  For example, if I have an array containing {7, 3, 8, 2}, and I 
        // want to set the value at position 1 to 100, I will have {7, 100, 8, 2}.
        void SetValue(const size_t& pos, const T& value)
        {
            const int NONE =0;
            if (pos< GetCount()&&pos>=NONE){
                dataArray[pos] = value;
                //return true;
            }
            else{
                throw "Invalid Position";
                //return false;
                
            }
            
        }
    };
}
