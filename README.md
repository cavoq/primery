# 🔢 Primery

> A fast prime number generator with multiple algorithms and parallel execution support.

![license](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![version](https://img.shields.io/badge/version-1.3-lightgrey.svg)

Primery generates prime numbers in a specified range `[x, y]` and benchmarks the performance of different algorithms. Supports both single-threaded and multi-threaded execution modes.

## 📊 Supported Algorithms

| Algorithm | Alias | Complexity |
|-----------|-------|------------|
| Trial Division | `td` | O(n√n) |
| Sieve of Eratosthenes | `soe` | O(n log log n) |
| Sieve of Sundaram | `sos` | O(n log n) |
| Sieve of Atkin | `soa` | O(n) |

## 🚀 Quick Start

### Build from Source

```bash
# Clone the repository
git clone https://github.com/yourusername/primery.git
cd primery

# Build
make build

# Run
./build/primery soa -i [2,1000000]
```

### Install Globally

```bash
sudo make install
primery soa -i [2,1000000]
```

### Using Docker

```bash
# Build image
docker build -t primery .

# Run
docker run --rm primery -i [2,100000] -m p soa
```

## 📖 Usage

```
primery [OPTIONS] <algorithm>
```

### Options

| Flag | Description | Default |
|------|-------------|---------|
| `-i, --interval` | Range `[start,end]` | `[2,1000]` |
| `-m, --mode` | `s\|single` or `p\|parallel` | `single` |
| `-t, --time` | `ns`, `ms`, or `s` | `ms` |
| `-o, --output` | Output file path | `primes.txt` |
| `-h, --help` | Show help | - |

### Examples

```bash
# Generate primes from 2 to 1 million using Sieve of Atkin
primery soa -i [2,1000000]

# Parallel execution with nanosecond timing
primery -i [234,100000] -t ns -m p sieveOfEratosthenes

# Save to custom file
primery soe -i [2,10000] -o my_primes.txt
```

## 🛠️ Build Commands

```bash
make build      # Build the project
make install    # Install to /usr/local/bin
make uninstall  # Remove installation
make clean      # Clean build artifacts
make package    # Create .tar.gz and .deb packages
```

## 📈 Benchmarks

> Tested on 11th Gen Intel Core i7-11800H @ 2.30GHz × 8

### Single-Threaded

| n | Eratosthenes | Sundaram | Atkin |
|---|--------------|----------|-------|
| 10⁵ | 0.718 ms | 0.602 ms | 0.936 ms |
| 10⁶ | 7.544 ms | 6.956 ms | 8.386 ms |
| 10⁷ | 66.149 ms | 65.015 ms | 62.988 ms |
| 10⁸ | 0.947 s | 1.007 s | **0.837 s** |
| 10⁹ | 10.956 s | 16.559 s | **8.839 s** |

### Multi-Threaded

| n | Eratosthenes | Sundaram | Atkin |
|---|--------------|----------|-------|
| 10⁵ | 3.197 ms | 27.105 ms | 10.941 ms |
| 10⁶ | 11.735 ms | 140.159 ms | 40.063 ms |
| 10⁷ | 62.772 ms | 1.195 s | 122.007 ms |
| 10⁸ | **0.49 s** | 11.984 s | 0.511 s |
| 10⁹ | 7.284 s | - | **3.903 s** |

### 💡 Conclusion

The **Sieve of Atkin** performs best for large ranges (10⁸+) in both single and multi-threaded modes. For smaller ranges, **Sieve of Sundaram** is competitive in single-threaded mode. Multi-threading provides significant speedup for large inputs, with Atkin achieving ~2.3x improvement at 10⁹.
