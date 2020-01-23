from pymavlink import mavutil
import time
# Create the connection
# Need to provide the serial port and baudrate
master = mavutil.mavlink_connection(
            '/dev/ttyACM0',
            baud=115200)
master.mav.command_long_send(
    master.target_system,
    master.target_component,
    mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
    0,
    1, 0, 0, 0, 0, 0, 0)

t = 0;
while (t<5):

master.mav.manual_control_send(1,500,0,0,0,0)
time.sleep(1)
t= t+1
#master.reboot_autopilot()
