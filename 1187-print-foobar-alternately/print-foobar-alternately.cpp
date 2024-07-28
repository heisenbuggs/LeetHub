class FooBar {
private:
    int n;
    int count;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        count = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            while(count == 1) {
                cv.wait(lck);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            count = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            while(count == 0) {
                cv.wait(lck);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            count = 0;
            cv.notify_all();
        }
    }
};