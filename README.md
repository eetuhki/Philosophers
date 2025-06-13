🍝 **Philosophers**

Solving the classic *Dining Philosophers* problem using threads and mutex locks.

Picture this:
Five philosophers sit around a circular table with a bowl of spaghetti. 
There's five forks, but each philosopher needs **two forks** to eat.
Who gets the forks first? The hungriest philosopher of course! 
And remember philosophers need to sleep and do some thinking too..!

💡 What This Project Demonstrates

- **Thread Management**: Creating and coordinating multiple threads safely
- **Mutex Synchronization**: Protecting shared resources (forks) from data race conditions  
- **Deadlock Prevention**: Implementing strategies to avoid circular wait conditions
- **Resource Scheduling**: Ensuring fair access to limited resources
- **Performance Optimization**: Balancing efficiency with safety in concurrent systems

🛠️ Technical Implementation

- **Language**: C
- **Concurrency Model**: POSIX threads (pthreads)
- **Synchronization**: Mutex locks for fork management
- **Memory Management**: Clean memory allocation and free'ing with no leaks

🚀 Key Features

- ⚡ **Zero Deadlocks**: Bulletproof synchronization strategy
- 🔄 **Fair Resource Distribution**: No philosopher starves
- 📊 **Real-time Monitoring**: Live status updates for each philosopher
- 🧠 **Memory Safe**: Valgrind-clean implementation
- ⚙️ **Configurable Parameters**: Adjustable timing and philosopher count
