#include <iostream>
#include <fstream>
#include <unordered_set>
#include<algorithm>

using std::cout;            using std::endl;
using std::string;          using std::unordered_set;
using std::ifstream;
/*
 * Note that you have to pass in the file as a single string
 * into the findWikiLinks function!
 * So we have to turn the passed-in file into a single string...
 * does that sound familiar at all?
 */
unordered_set<string> findWikiLinks(const string& page_html) {
    // TODO: delete this return statement and implement the
    //       function!
    unordered_set<string> ret;
    auto curr = page_html.begin();
    auto end = page_html.end();
    string toFind = "<a href=\"/wiki/";
    string elem = "";

    while(curr != end){
        auto found = std::search(curr, end, toFind.begin(), toFind.end());
        if(found == toFind.begin()){  // find the start of the link
            curr = curr + toFind.length();
            auto rear = std::find(curr, end, '\"');
            elem = std::string(curr, rear); 
            if(std::all_of(elem.begin(), elem.end(), 
                                     [](char c) {return (c != '#' || c != ':');}))
                 ret.insert(elem);
        }
        if(found == end)
            break;
        ++curr;
    }           
    return ret;
}

int main() {
    /* Note if your file reading isn't working, please go to the
     * projects tab on the panel on the left, and in the run section,
     * uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */

    cout << "Enter a file name: ";
    string filename;  
    getline(std::cin, filename);
    string page_html;

    // TODO: Create a filestream from the filename, and convert it into
    //       a single string of data called page_html (declared above)

    // Write code here
    string line;
    page_html = "";
    ifstream fs("/home/tobi/CSAPP-lab-bomb/bomb/"
                         + filename);
    while(getline(fs, line)){
       page_html += line + " ";
    }

    unordered_set<string> validLinks = findWikiLinks(page_html);

    // TODO: Print out the validLinks set above.
    //       You can print it out in any format; this is just for you
    //       to be able to compare your results with the [output] results
    //       under the /res folder.

    // Write code here
    for(string i: validLinks)
        cout << i << "\n";
    cout << endl;
    return 0;
}
