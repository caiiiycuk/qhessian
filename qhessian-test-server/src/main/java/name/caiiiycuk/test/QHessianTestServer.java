package name.caiiiycuk.test;

import org.mortbay.jetty.Connector;
import org.mortbay.jetty.Handler;
import org.mortbay.jetty.Server;
import org.mortbay.jetty.nio.SelectChannelConnector;
import org.mortbay.jetty.servlet.Context;
import org.mortbay.jetty.servlet.ServletHolder;
import org.mortbay.thread.QueuedThreadPool;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.caucho.hessian.test.TestHessian2Servlet;
import com.caucho.hessian.test.TestHessianServlet;

public class QHessianTestServer {
	

    private static final Logger logger = LoggerFactory.getLogger(QHessianTestServer.class);
	
	public static void main(String[] args) {
		QueuedThreadPool threadPool = new QueuedThreadPool(20);
		
		SelectChannelConnector selectChannelConnector = new SelectChannelConnector();
		selectChannelConnector.setPort(8080);

		final Server server = new Server();
		server.setConnectors(new Connector[] { selectChannelConnector });
		server.setThreadPool(threadPool);

		Context root = new Context(server, "/", Context.SESSIONS);
		
		root.addServlet(new ServletHolder(new TestHessianServlet()), "/test1");
		root.addServlet(new ServletHolder(new TestHessian2Servlet()), "/test2");
		
		server.setHandlers(new Handler[] { root	});
		
        Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
            @Override
            public void run() {
            	try {
					server.stop();
				} catch (Exception e) {
					logger.error(e.getMessage(), e);
				}
            }
        }));
        
		try {
			server.start();
			server.join();				
		} catch (Exception e) {
			logger.error(e.getMessage(), e);
		}
	}

}
