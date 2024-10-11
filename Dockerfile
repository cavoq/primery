FROM debian:bookworm-slim

ENV PROJECT=primery
ENV VERSION=1.3

RUN apt-get update && \
    apt-get install -y g++ make && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /primery

COPY . .

RUN make build

ENTRYPOINT ["./primery"]