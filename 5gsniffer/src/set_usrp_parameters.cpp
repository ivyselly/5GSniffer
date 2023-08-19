#include "set_usrp_parameters.h"
#include <uhd/usrp/multi_usrp.hpp>
//#include <uhd/usrp/mboard_eeprom.hpp>

void set_usrp_parameters(uhd::usrp::multi_usrp::sptr usrp, const struct config& cfg) {
    // Create a USRP object with the desired device arguments from the config
    //uhd::usrp::multi_usrp::sptr usrp = uhd::usrp::multi_usrp::make(cfg.usrp_device_args);

    // Lock mboard clocks
    usrp->set_clock_source(cfg.ref);

    // Set other USRP parameters here (sample rate, frequency, gain, etc.)
    // Example:
    usrp->set_rx_rate(cfg.sample_rate);
    usrp->set_rx_freq(cfg.frequency);
    usrp->set_rx_bandwidth(cfg.bw);
    usrp->set_rx_subdev_spec(cfg.subdev_spec);
    usrp->set_rx_antenna(cfg.ant);
     usrp->set_tx_freq(cfg.frequency);
     usrp->set_tx_bandwidth(cfg.bw);
    usrp->set_time_source(cfg.time);
    // Add other parameter settings as needed based on your configuration struct

    // Set the subdevice specification
    usrp->set_rx_subdev_spec(cfg.subdev_spec);
     uhd::usrp::subdev_spec_t subdev_spec("A:A");
    usrp->set_tx_subdev_spec(subdev_spec);
    // Create a TX streamer
    //uhd::stream_args_t stream_args("sc16", "sc16");  // Data format: complex shorts
    //uhd::tx_streamer::sptr tx_stream = usrp->get_tx_stream(stream_args);

    // Prepare data to transmit
    //const size_t num_samples = 1024;
    //std::vector<std::complex<short>> tx_data(num_samples, {1000, 0});  // Example data

    // Transmit the data
   // tx_stream->send(&tx_data[0], num_samples);

    // Clean up and exit
   // tx_stream->close();
     
     
    // Set other USRP parameters here based on your config struct
    // For example, set_rx_antenna, set_time_source, etc.
}

