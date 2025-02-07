#pragma once

#include <AP_HAL/AP_HAL_Boards.h>
#include <stdint.h>
#include <AP_HAL/Semaphores.h>
#include <pthread.h>

namespace QURT
{

class Semaphore : public AP_HAL::Semaphore
{
public:
    friend class BinarySemaphore;
    Semaphore();
    bool give() override;
    bool take(uint32_t timeout_ms) override;
    bool take_nonblocking() override;
    bool check_owner(void);
protected:
    // qurt_mutex_t _lock;
    pthread_mutex_t _lock;
    pthread_t owner;
};


class BinarySemaphore : public AP_HAL::BinarySemaphore
{
public:
    BinarySemaphore(bool initial_state=false);

    bool wait(uint32_t timeout_us) override;
    bool wait_blocking(void) override;
    void signal(void) override;

protected:
    Semaphore mtx;
    pthread_cond_t cond;
    bool pending;
};

}
