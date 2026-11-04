#ifndef CPU_ENGINE_HPP
#define CPU_ENGINE_HPP

#include <cstdint>
#include <vector>
#include <string>

class CPUEngine {
public:
    CPUEngine();
    ~CPUEngine();

    bool initialize();
    uint32_t decodeAndExecute(uint32_t instruction);
    void resetRegisters();
    uint64_t getRegister(int regIndex) const;
    void setRegister(int regIndex, uint64_t value);

private:
    uint64_t registers[32];
    uint64_t programCounter;
    bool jitEnabled;
};

#endif // CPU_ENGINE_HPP
