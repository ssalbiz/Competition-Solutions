This is the C++ starter package.  It is a fully functional strategy, albeit a simple one.  You can submit the .zip file that these files came in, and it should work.  

In order to make the strategy more intelligent, you want to change the contents of Strategy.cc.  Replace the MakeMove function with something more intelligent than "return rock".  

All kinds of information about your previous moves and your opponent's previous moves is available through the Helper object.  For more hints about how to use this object to create a more intelligent strategy, check out the C++ documentation on the contest website, at

http://csclub.uwaterloo.ca/contest



Here is a brief explanation of what all the files in this directory are.

compile.sh -- This is a script which contains information about how to compile your entry. Most of you will not have to change this. The only reason you would have to change this is if you added more code files to your submission, or changed the name of a file, or something. However, you do need to make sure that this file goes into the zip file that you submit. Otherwise, the contest environment will not be able to compile your entry.

run.sh -- This is a script which contains information about how to run your program once it is compiled. Again, most of you will not need to ever change this. You would only have to change the contents of run.sh if you were changing the name of your program or something. Be sure to include this file in the zip file that you submit.

Helper.cc and Helper.h -- These two files define the Helper object that you use to get information about your previous moves and your opponent's previous moves.

Strategy.cc -- This is the file that you care about, and should be the only file that you make changes to unless you have a decent idea of what you are doing. This file contains the "brain" of your strategy.
