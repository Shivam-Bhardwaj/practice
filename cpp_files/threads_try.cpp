#include <iostream>
#include <thread>

void threadFunctionEven()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
  std::cout << "Even thread\n";
}

/* Student Task START */
void threadFunctionOdd()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
  std::cout << "Odd thread\n";
}
/* Student Task END */

int main()
{
  /* Student Task START */

  for (int i = 0; i < 6; ++i) {
    if(i%2){
      std::thread odd(threadFunctionOdd);
      odd.detach();
    } else{
      std::thread even(threadFunctionEven);
      even.detach();
    }
  }
  /* Student Task END */

  // ensure that main does not return before the threads are finished
  std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
  std::cout << "\nEnd of main is reached" << std::endl;
  return 0;
}
