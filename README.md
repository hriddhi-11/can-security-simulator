#  Automotive CAN Network Attack & Defense Simulator

> A comprehensive CAN bus security testing framework demonstrating automotive network vulnerabilities and defense mechanisms

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Protocol](https://img.shields.io/badge/Protocol-CAN%202.0B-green.svg)](https://en.wikipedia.org/wiki/CAN_bus)
[![Security](https://img.shields.io/badge/Focus-Automotive%20Security-red.svg)](https://en.wikipedia.org/wiki/Automotive_security)

## 📋 Overview

This project implements a complete **CAN 2.0B protocol stack** from scratch in C, featuring multi-node automotive ECU simulation with **real-time intrusion detection** capabilities. The simulator demonstrates common CAN bus attack vectors (spoofing, DoS) and implements security mechanisms to detect and block malicious traffic.

Built to understand automotive cybersecurity at the protocol level - no libraries, pure implementation.

## ✨ Key Features

- **Complete CAN Protocol Implementation**
  - Frame construction and parsing
  - CRC-15 error detection
  - Bit stuffing algorithm
  - Message arbitration simulation

- **Multi-Node Automotive Network**
  - ECU node (Engine Control Unit)
  - Dashboard node with warning system
  - Attacker node (security testing)
  - Detector node (intrusion prevention)

- **Security Features**
  - Real-time message source tracking
  - Spoofing attack detection
  - Malicious message filtering
  - Security event logging
  - 100% attack detection rate

- **Professional Code Structure**
  - Modular architecture
  - Separate compilation units
  - Clear separation of concerns
  ## 🎬 Demo

### Normal Operation
```
--- Cycle 1 ---
[ECU] Sending legitimate data...
[DASHBOARD] RPM: 900
[DASHBOARD] Temperature: 74°C
[DASHBOARD] Speed: 0 km/h
[DASHBOARD] Fuel: 99%
```

### Security in Action
```
--- Cycle 3 ---
[ECU] Sending legitimate data...
[ATTACKER] 🔴 SPOOFING! Injecting fake RPM=9999 (ID:0x100)
[DETECTOR] 🚨 ATTACK DETECTED! Blocking malicious frame (ID:0x100, Source:1)
[DETECTOR] Security Report: 4 legitimate, 1 blocked
[DASHBOARD] RPM: 1100  ← Real value shown, attack blocked!
[DASHBOARD] Temperature: 75°C
[DASHBOARD] Speed: 0 km/h
[DASHBOARD] Fuel: 97%
```

**Result:** Dashboard never receives malicious data - 100% protection achieved! 

## 🏗️ Architecture
```
┌─────────────┐
│  ECU Node   │ → Generates legitimate sensor data
└──────┬──────┘
       ↓
┌──────────────────────────────┐
│        Raw CAN Bus           │
│  (Contains all messages)     │
└──────┬───────────────────────┘
       ↓
┌──────────────┐    ┌────────────────┐
│ Attacker     │ →  │   Detector     │
│ (Injects     │    │  (Filters &    │
│  malicious)  │    │   Blocks)      │
└──────────────┘    └────────┬───────┘
                             ↓
                    ┌─────────────────┐
                    │  Filtered Bus   │
                    │ (Clean only)    │
                    └────────┬────────┘
                             ↓
                    ┌─────────────────┐
                    │   Dashboard     │
                    │  (Protected!)   │
                    └─────────────────┘
```

### Components

- **CAN Bus** - Message queue simulation
- **ECU Node** - Simulates engine sensors (RPM, temperature, speed, fuel)
- **Dashboard Node** - Displays sensor data with threshold warnings
- **Attacker Node** - Injects spoofed messages for security testing
- **Detector Node** - Real-time intrusion detection and message filtering
## 🚀 Installation

### Prerequisites
- GCC compiler
- Make (optional)
- Linux/macOS/Windows with MinGW

### Clone and Build
```bash
# Clone the repository
git clone https://github.com/[your-username]/can-security-simulator.git
cd can-security-simulator

# Compile
gcc main.c can_frame.c can_crc.c can_stuffing.c can_bus.c \
    ecu_node.c dashboard_node.c attacker_node.c detector_node.c \
    -o can_simulator

# Run
./can_simulator
```

## 💻 Usage

### Basic Simulation
```bash
./can_simulator
```
Runs 15 cycles with attacks on cycles 3, 6, 9, 12, 15.

### Modify Attack Pattern
Edit `main.c`:
```c
// Attack every 3rd cycle
if(cycle % 3 == 0) {
    attacker_spoof_rpm(&raw_bus, 9999);
}
```

### Adjust Simulation Length
```c
for(int cycle = 1; cycle <= 15; cycle++)  // Change 15 to desired cycles
```

## 🔬 Technical Implementation

### CAN Protocol Features

**CRC-15 Calculation**
- Polynomial: 0x4599
- Bit-by-bit processing
- XOR-based error detection

**Bit Stuffing**
- Inserts opposite bit after 5 consecutive identical bits
- Maintains bus synchronization
- Automatic destuffing on receive

**Frame Structure**
```c
typedef struct {
    uint16_t id;        // 11-bit identifier
    uint8_t dlc;        // Data length (0-8)
    uint8_t data[8];    // Payload
    uint8_t rtr;        // Remote transmission request
    uint16_t crc;       // CRC-15 checksum
    uint8_t source;     // Message source tracking
} CAN_Frame;
```

### Security Implementation

**Attack Detection**
- Source field tracking (0=ECU, 1=Attacker)
- Message filtering based on source validation
- Real-time blocking of malicious frames
- Security event logging and reporting

**Detection Rate:** 100% (5/5 attacks detected and blocked)

## 📚 What I Learned

- Deep understanding of CAN 2.0B protocol specification
- Bit-level manipulation and error detection algorithms
- Multi-node embedded system architecture
- Automotive cybersecurity threats and countermeasures
- Professional C code organization and modularity

## 🔮 Future Enhancements

- [ ] DoS (Denial of Service) attack simulation
- [ ] Replay attack detection
- [ ] Message frequency analysis
- [ ] Python visualization tool for real-time traffic monitoring
- [ ] Port to STM32 hardware with real CAN transceivers
- [ ] Machine learning-based anomaly detection

## 👤 Author

- GitHub: [@your-username](https://github.com/hriddhi-11)
- LinkedIn: [Your LinkedIn](https://linkedin.com/in/hriddhi)
- Email: hribiswas008@gmai.com

## 📄 License

This project is open source and available under the MIT License.

---

**Built as part of embedded systems learning journey - demonstrating protocol implementation and automotive security concepts.**