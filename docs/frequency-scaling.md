When you run the google-benchmark it might print a message like:

***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.

This means the operating system (OS) can dynamically change the frequency while the program is running.
Modern processors are designed to run at multiple frequencies. The frequency is scaled up/down by the
operating system in order to save power or to improve performance depending on the situation. For example,
when the load factor is low, the OS can scale down the CPU because there is not much work to be done. On the
other hand while running expensive compute operations the frequency is scaled up to execute the task as quickly
as possible. For more details please see: (https://wiki.archlinux.org/index.php/CPU_frequency_scaling).

Now when running a performance benchmark you want to fix the frequency otherwise the performance numbers
will be noisy. So you must fix the frequency before running the benchmark. Without fixing the frequency
wide variation in results may be observed (specially for small data sizes).

On Ubuntu machines an easy way to fix the frequency is to install cpufrequtils:

```sh
sudo apt-get install cpufrequtils
```

Then edit the following file (if it doesn't exist, create it):

```
sudo vi /etc/default/cpufrequtils
```

And add the following line to it:

```sh
GOVERNOR="performance"
```
For more details see this post:
http://askubuntu.com/questions/523640/how-i-can-disable-cpu-frequency-scaling-and-set-the-system-to-performance

