#!/bin/bash

echo ""
echo "[test.sh] CHECKING /"
curl localhost:7348/

# -------------------------------------------------------------

echo ""
echo ""
echo "[test.sh] CHECKING /auth/0 WITH MALFORMED REQUEST"
curl -d "" -X POST localhost:7348/auth/0

echo ""
echo "[test.sh] CHECKING /auth/1 WITH MALFORMED REQUEST"
curl -d "" -X POST localhost:7348/auth/1

echo ""
echo "[test.sh] CHECKING /auth/2 WITH MALFORMED REQUEST"
curl -d "" -X POST localhost:7348/auth/2

echo ""
echo "[test.sh] CHECKING /auth/3 WITH MALFORMED REQUEST"
curl -d "" -X POST localhost:7348/auth/3

echo ""
echo "[test.sh] CHECKING /auth/4 WITH MALFORMED REQUEST"
curl -d "" -X POST localhost:7348/auth/4

# -------------------------------------------------------------

echo ""
echo ""
echo "[test.sh] CHECKING /auth/0"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/0

echo ""
echo "[test.sh] CHECKING /auth/1"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/1

echo ""
echo "[test.sh] CHECKING /auth/2"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/2

echo ""
echo "[test.sh] CHECKING /auth/3"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/3

echo ""
echo "[test.sh] CHECKING /auth/4"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/4

echo ""
echo "[test.sh] CHECKING /auth/9999"
curl -d "{}" -H 'Content-Type: application/json' -X POST localhost:7348/auth/9999

# -------------------------------------------------------------

echo ""
echo "[test.sh] DONE"