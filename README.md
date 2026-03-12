# MP3 Tag Reader (C)
# 📌 Project Description

The MP3 Tag Reader is a C-based application that reads and displays metadata information stored in MP3 files. MP3 files contain ID3 tags that store details such as the song title, artist name, album, year, and genre. This project extracts these tags and displays the information to the user.

# 🎯 Objective

To understand how metadata is stored in MP3 files.

To implement a program that reads ID3 tags from audio files.

To practice file handling and binary data processing in C.

# 🧠 Concepts Used

File Handling in C

Binary File Processing

Structures

String Manipulation

ID3 Tag Format

# ⚙️ How the System Works

The program takes an MP3 file as input.

It reads the ID3 tag section present in the file.

The tag data is extracted using structures and file pointers.

Information such as Title, Artist, Album, Year, and Genre is decoded.

The extracted metadata is displayed to the user.

# ✨ Features

Reads metadata from MP3 files

Displays song information clearly

Supports ID3 tag format

Simple command-line interface

# 🚀 Advantages

Helps understand the structure of MP3 files

Demonstrates binary file processing

Useful for managing and viewing audio file information

# 💡 Applications

Music library management systems

Media players

Audio file information tools

Digital music organization systems

# 🛠️ Technologies Used

Programming Language: C

Concepts: File Handling, Structures, Binary Data Processing

Compiler: GCC

Platform: Linux / Terminal

# 📂 Project Structure
MP3_Tag_Reader/
│

├── main.c

├── read_tags.c

├── edit_tags.c

├── header.h

└── sample_mp3/

# ▶️ Steps to Run the Project
1. Compile the Program
gcc *.c
2. Run the Program
./a.out sample.mp3
# 📊 Example Output
Title  : Shape of You
Artist : Ed Sheeran
Album  : Divide
Year   : 2017
Genre  : Pop
# 📚 Learning Outcomes

Understanding of MP3 file structure and ID3 tags

Practical experience with binary file reading in C

Implementation of metadata extraction techniques

Improved knowledge of file handling and structures
