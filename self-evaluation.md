# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: Yes

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: command.cpp Command::runCommand

invalid movie type: movieFactory.cpp MovieFactory::create, stockManager.cpp StockManager::getMovie

invalid customer ID: customerManager.cpp CustomerManager::getCustomer
 
invalid movie: xMovieFactory.cpp xMovieFactory::getMovie (all)

factory classes: xMovieFactory.h, xMovieFactory.cpp (all)

hashtable: customerManager.cpp. The hashtable is used to store customers. it hashes their ID into an array of vectors in case of collisions (though ideally each vector is kept very short)

container used for comedy movies: comedyMovies in ComedyMovieFactory.h

function for sorting comedy movies: ComedyMovieFactory.cpp ComedyMovieFactory::sortMovies()

function where comedy movies are sorted: ComedyMovieFactory.cpp ComedyMovieFactory::makeMovie()

functions called when retrieving a comedy movie based on title and year: stockManager.cpp StockManager::getMovie, comedyMovieFactory.cpp ComedyMovieFactory::getMovie

functions called for retrieving and printing customer history: command.cpp Command::runCommand, history.cpp History::execute

container used for customer history: history in customer.cpp and customer.h

functions called when borrowing a movie: command.cpp Command::runCommand, borrow.cpp Borrow::execute

explain borrowing a movie that does not exist: it attempts to get the movie using getMovie but it returns nullptr with an error message so the function returns early

explain borrowing a movie that has 0 stock: it gets the movie but sees that it has 0 stock so it states an error message then returns early

explain returning a movie that customer has not checked out: the return function searches the customers history to see if theyve checked it out and not returned it, and returns early with an error if not

any static_cast or dynamic_cast used: ClassicMovieFactory::getMovie, Return::execute

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? YES




Q: Total points: 30