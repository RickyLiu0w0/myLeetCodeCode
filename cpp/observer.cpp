/**
 * 线程安全的观察者代码
 */

#include "AllInclude.h"
using namespace std;

class Subject;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(Subject&) = 0;
};

class Subject {
public:
    /**
     *  添加观察者
     */
    void add(weak_ptr<Observer> observer) {
        lock_guard<mutex> lock(m_mutex);
        shared_ptr<Observer> sp = observer.lock();  // 将weak提升为share ptr

        // 确保不重复添加同一观察者
        if (find_if(m_observers.begin(), m_observers.end(),
                    [&](const weak_ptr<Observer>& o) -> bool { return o.lock() == sp; }) == m_observers.end()) {
            m_observers.emplace_back(move(observer));
        }
    }

    void del(weak_ptr<Observer> observer) {
        lock_guard<mutex> lock(m_mutex);
        auto sp = observer.lock();
        auto it = find_if(m_observers.begin(), m_observers.end(),
                          [&](const weak_ptr<Observer>& o) { return o.lock() == sp; });
        if (it != m_observers.end()) {
            m_observers.erase(it);
        }
    }

    void notify() {
        lock_guard<mutex> lock(m_mutex);
        for (auto it = m_observers.begin(); it != m_observers.end();) {
            auto sp = it->lock();
            if (sp) {
                sp->update(*this);
                it++;
            } else {
                m_observers.erase(it);
            }
        }
    }

private:
    vector<weak_ptr<Observer>> m_observers;  // 存储观察者
    mutex m_mutex;
};

class Observer1 : public Observer {
public:
    void update(Subject&) override {
        cout << "1号收到通知\n";
    }
};

class Observer2 : public Observer {
public:
    void update(Subject&) override {
        cout << "2号收到通知\n";
    }
};

int main() {
    auto subject = make_shared<Subject>();
    auto observer1 = make_shared<Observer1>();
    auto observer2 = make_shared<Observer2>();

    subject->add(observer2);
    subject->add(observer1);
    subject->notify();
    subject->del(observer2);
    subject->notify();

    return 0;
}