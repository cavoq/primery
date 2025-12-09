FROM debian:bookworm-slim AS builder

RUN apt-get update && \
    apt-get install -y g++ make cmake && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /primery

COPY . .

RUN make build

FROM debian:bookworm-slim

COPY --from=builder /primery/build/primery /usr/local/bin/primery

ENTRYPOINT ["primery"]
