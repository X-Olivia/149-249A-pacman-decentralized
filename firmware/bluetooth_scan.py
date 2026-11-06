# import asyncio
# from bleak import BleakScanner

# FFE0 = "0000ffe0-0000-1000-8000-00805f9b34fb"
# NAMES = ("hmsoft", "hm-10", "hm10", "bt05", "cc41", "ble-")

# async def main():
#     found = await BleakScanner.discover(timeout=10.0, return_adv=True)
#     for addr, (dev, adv) in sorted(found.items(), key=lambda kv: -kv[1][1].rssi):
#         name = adv.local_name or dev.name or ""
#         uuids = [u.lower() for u in adv.service_uuids]
#         hit = FFE0 in uuids or name.lower().startswith(NAMES)
#         if hit or adv.rssi > -60:
#             print(f"{adv.rssi:4} dBm | {name or 'None'} | {addr}{'  <-- HM-10?' if hit else ''}")

# asyncio.run(main())
import asyncio
from bleak import BleakClient, BleakScanner

NAME = "149_G14_EV"
FFE1 = "0000ffe1-0000-1000-8000-00805f9b34fb"  # HM-10 data characteristic

def on_reply(_, data):
    print("robot says:", data.decode(errors="ignore").strip())

async def main():
    dev = await BleakScanner.find_device_by_filter(
        lambda d, adv: (adv.local_name or d.name or "") == NAME,
        timeout=10,
    )
    if not dev:
        print("Module not found"); return

    async with BleakClient(dev) as client:
        await client.start_notify(FFE1, on_reply)
        print("Connected. Type f/b/l/r/s, or q to quit.")
        loop = asyncio.get_event_loop()
        while True:
            cmd = await loop.run_in_executor(None, input, "> ")
            if cmd == "q":
                await client.write_gatt_char(FFE1, b"s", response=False)
                break
            if cmd:
                await client.write_gatt_char(FFE1, cmd[0].encode(), response=False)

asyncio.run(main())