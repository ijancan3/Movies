This is an expanded and re-imagined version of the C++ program required for the Scripting and Programming course I have taken at WGU. It is a simple movie "database" that uses the
C++ ifstream objects to read/write to file.

Things I have learned while creating this program:

  1) Modular design: The main() method is relatively free of clutter, only being used to create the needed object and use the methods to parse and run the primary loop.

  2) Manipulating a .txt file to read and write to it. This is done using an ifstream class. The movies are stored in the text file using a '*' delimited string, and the file is read line by line. Then, the '*' delimited values are separated into individual string objects, which are then converted to their proper types (if needed for the int variables, such as rating), and the add() method is called that creates the movie objects using the Movie constructor. These objects are stored in a vector for the duration of runtime. The setMovieFile() method also writes all changes to the text file by truncating the file and then writing the objects from the working memory as a '*' delimited string.
  
  3) How to create an enumerated type (Genre) and use it to store the genre values. 
  
  4) How to perform input validation (readInput() method) to ensure that the user does not enter a non-integer value at the menu, as well as to flush the stream if the user does accidentally do so.
  
  5) Random number generation using the <ctime> library to generate a randomized ID when entering a new movie (generateID() method), as well as to validate the randomly generated ID against the current IDs to make sure no duplicates are created.
  
  6) How to parse through the movie file to do a rudimentary 'keyword' search. 
  
  In the original project, which I have ported to Java (available in the StudentRoster repository), the objects required storage in an array of pointers, meaning memory management through the use of destructors was important. I have intentionally avoided using pointers and arrays in this program due to the simplicity of vector storage. 
  
  These are the following iterations I plan on doing for this project:
  
    1) Link it to a small MySql database instead of a .txt file, and use DQL and DML language to maintain the database.
    
    2) Refine the keyword search to return closest match instead of exact, and to be case insensitive. 
