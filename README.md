1.  Dynamic Array Implementation & Ability to add items:

    - I created a class "Clients" that dynamically allocates an array of AllClientData objects (clientFile = new AllClientData[capacity];).
    I also implemented a destructor that deallocates memory from the dynnamic array to prevent memory leaks. Within the addClient() function I created a new dynamic array with 1 space appended to store new client file. I used a loop to iterate through each existing client file and copy it to the newCientArray. I had to make sure I deleted the memory that was previously allocated for client file and re-assign clientFile with the newClientArray created. Then I updated the array size for the next iteration.

2.  Reading data from external file:

    - I declared a ifstream class named "file" to open the external file bank_full.csv and declared a string class object named "line" to store values extracted. I use the getline() function to store rows from the external file into "line" and used a for loop to read in capacity number of rows from the external file. I declared a stringstream class named "parse" which splits values from rows stored in "line" variable into individual strings.

3.  Data Organization with Structs and Classes:

    - I created a class named "Clients" to encapsulate multiple structs where the last struct is nested with the previous 3. I did this after getting feedback to better organize the data members. I grouped related data members in seprate structs. I used int & string types. I used getline() and stringstream to parse and store CSV data into struct members.

4.  User Interface:

    - I include a main menu interface in the main body to display 5 options/operations to the user. I made it very user friendly with simple prompts. I organized the output results for readability. I keep the main menu open using a while loop until the user exits the program by inputting 5.


5.  Data Search Functionality:

    - I created search capabilities for a client by ID in the search() function. I used a for loop to iterate over the dynamic array and compare IDs (if (clientFile[i].clientInfo.id == idSearch)). I displayed full client details if a match is found and an error message if no match is found. I used a linear algorithm but will adjust to use a binary search since I am using a large data set

6.  Data Validation and Error Handling:





7.  Based on feedback from the stand up video, I implemented nested structures under struct "ClientRecord" to better organize my code and improve readability. To do this I created multiple structs that group related information rather than having all data members in one struct. I also renamed my variables to improve logic and readabilty. For example I changed pointer variable Client* clients to AllClientData* clientFile;