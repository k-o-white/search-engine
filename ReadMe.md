<h1>Search Engine</h1>

<p>This search engine is a console application, that can be run on any server or computer. It's configurable via file "config.json", so you can change files' paths that the engine will search for.</p>

<h2>This project was created using the following technologies</h2>

<ul>
    <li><a href="#">C++17</a></li>
    <li><a href="#">CMake 3.23.2</a></li>
    <li><a href="#">Nlohmann JSON Library</a></li>
    <li><a href="#">GoogleTest Framework</a></li>
    <li><a href="#">MinGW w64 9.0</a></li>
</ul>

<h2>How to build and run this app</h2>

<ul>
    <li>
        Download project in ZIP and then unpack it or clone this repository to your PC by command:
        <blockquote>
            <code>git clone https://github.com/k-o-white/search-engine.git</code></blockquote>
        and then go to folder of project
        <blockquote>
            <code>cd search-engine</code>
        </blockquote>
    </li>
    <li>
        Create folder for building app and go to it:
        <blockquote>
            <code>mkdir build</code><br/>
            <code>cd build</code>
        </blockquote>
    </li>
    <li>
        Input command:
        <blockquote>
            <code>cmake .. -G "MinGW Makefiles"</code><br/>
            <code>cmake --build . --config Release --target SearchEngine</code>
        </blockquote>
    </li>
    <li>
        Go to source directory of build and run SearchEngine.exe:
        <blockquote>
            <code>cd src</code><br/>
            <code>start SearchEngine.exe</code>
        </blockquote>
    </li>
</ul>

<h2>How does this engine work</h2>

<ul>
    <li>
        Before launching the app it's necessary to put text files paths you wanted to this engine for search by the "files" key of "config.json" file and your queries to "requests.json" file.<br/>
        For example:
        <blockquote>
            config.json
        </blockquote>
        <blockquote>
            <code>
                {
                    "config": {
                        "name": "Search Engine",
                        "version": "0.1",
                        "max_responses": 5
                    },
                    "files": [
                        "../resources/file001.txt",
                        "../resources/file002.txt",
                        "../resources/file003.txt",
                        "../resources/file004.txt"
                    ]
                }
            </code>
        </blockquote>
    </li>
    <li>
        After running the app object of "ConverterJSON" class will be looking for "config.json" and "requests.json" files and will try to serialize them. If "config.json" or "requests.json" are missing or "config.json" is empty or programm version in "config.json" doesn't match with actual version, the engine will throw appropriate exception, else it will get required data to the private field of object such as text file paths and requests' strings.</li>
    <li>
        Then "InvertedIndex" class' object will parse .txt files from paths that "ConverterJSON" object got from "config.json" file to unique words and will count the number of entries of each word in eacg file.
    </li>
    <li>
        Finally "SearchServer" object will calculate the relative relevance for each requests in each file and counting results will be put in "answers.json" file.
    </li>
</ul>