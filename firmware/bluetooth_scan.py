import asyncio
from bleak import BleakClient, BleakScanner

NAME = "149_G14_EV"
ID = "0000ffe1-0000-1000-8000-00805f9b34fb"  # HM-10 data characteristic

def on_reply(_, data):
    print("robot says:", data.decode(errors="ignore").strip())

def is_my_module(device, advertisement):
    name = advertisement.local_name or device.name or ""
    return name == NAME

async def main():
    dev = await BleakScanner.find_device_by_filter(is_my_module, timeout=10)
    if not dev:
        print("Module not found")
        return

    #CHECK STARTING HERE AND ADD COMMENTS
    async with BleakClient(dev) as client:
        await client.start_notify(ID, on_reply)
        print("Connected! Type w,a,s,d, space, or q to quit.")
        loop = asyncio.get_event_loop()
        while True:
            cmd = await loop.run_in_executor(None, input, "> ")
            if cmd == "q":
                await client.write_gatt_char(ID, b"s", response=False)
                break
            if cmd:
                await client.write_gatt_char(ID, cmd[0].encode(), response=False)

asyncio.run(main())